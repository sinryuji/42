#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <netdb.h>

typedef struct s_client
{
  int fd;
  int id;
  struct s_client *next;
}               t_client;

int g_id;
int sockfd;
int max_fd;
t_client *g_clients = NULL;

void ft_putchar(char *str)
{
  write(1, str, strlen(str));
}

void fatal()
{
  write(2, "Fatal error\n", strlen("Fatal error\n"));
  close(sockfd);
  exit(1);
}

void init_fdset(fd_set *set)
{
  t_client *tmp;
  tmp = g_clients;
  FD_ZERO(set);
  max_fd = sockfd;
  while (tmp != NULL)
  {
    FD_SET(tmp->fd, set);
    if (max_fd < tmp->fd)
      max_fd = tmp->fd;
    tmp = tmp->next;
  }
  FD_SET(sockfd, set);
}

void send_all(char *str, int fd)
{
  t_client *tmp;
  tmp = g_clients;

  //     ft_putchar(str);
  while (tmp)
  {
    if (tmp->fd != fd)
      send(tmp->fd, str, strlen(str), 0);
    tmp = tmp->next;
  }

}

int get_id(int fd)
{
  t_client *tmp = g_clients;
  while (tmp)
  {
    if (tmp->fd == fd)
      return tmp->id;
    tmp = tmp->next;
  }
  return -1;
}

int rm_client(int fd)
{
  t_client *tmp = g_clients;
  t_client *del;

  int id = get_id(fd);
  if (tmp && tmp->fd == fd)
  {
    g_clients = tmp->next;
    free(tmp);
  }
  else
  {
    while (tmp && tmp->next && tmp->next->fd != fd)
      tmp = tmp->next;
    del = tmp->next;
    tmp->next = tmp->next->next;
    free(del);
  }
  return (id);
}

int add_client(int fd)
{
  t_client *tmp = g_clients;
  t_client *new;

  if ((new = calloc(1, sizeof(t_client))) == NULL)
    fatal();
  new->fd = fd;
  new->id = g_id++;
  new->next = NULL;
  if (!g_clients)
    g_clients = new;
  else
  {
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = new;
  }
  return (new->id);
}

void ex_msg(int fd, char *buff)
{
  int i = 0;
  int j = 0;
  char msg[8000];
  char tmp[8000];

  bzero(&msg, 8000);

  while (buff[i])
  {
    tmp[j] = buff[i];
    j++;
    if (buff[i] == '\n')
    {
      sprintf(msg, "client %d: %s", get_id(fd), tmp);
      send_all(msg, fd);
      j = 0;
      bzero(tmp, strlen(tmp));
      bzero(msg, strlen(msg));
    }
    i++;
  }
}


int main (int ac, char **av)
{
  if (ac != 2)
  {
    fatal();
  }
  int connfd, port, ret, id, size;
  socklen_t    len;
  struct sockaddr_in servaddr, cli;
  fd_set set_read;
  char str[1024];
  char buff[1024];
  char *msg;
  t_client *tmp;
  bzero(buff, 1024);
  bzero(str, 1024);

  //socket creation
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
  {
    fatal();
  }
  bzero(&servaddr, sizeof(servaddr));
  port = atoi(av[1]);
  if (port <= 0)
    fatal();
  // assign IP, PORT 
  servaddr.sin_family = AF_INET; 
  servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
  servaddr.sin_port = htons(port);

  // Binding newly created socket to given IP and verification 
  if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
    fatal();
  }
  if (listen(sockfd, 10) != 0) {
    printf("cannot listen\n"); 
    exit(0); 
  }
  if ((g_clients = malloc(sizeof(t_client))) == NULL)
    fatal();
  g_clients->next = NULL;
  len = sizeof(cli);
  g_id = 0;
  while (1)
  {
    init_fdset(&set_read);
    ret = select(max_fd + 1, &set_read, NULL, NULL, NULL);
    if (ret > 0)
    {
      if (FD_ISSET(sockfd, &set_read))
      {
        connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
        id = add_client(connfd);
        if (max_fd < connfd)
          max_fd = connfd;
        sprintf(str, "server: client %d just arrived\n", id);
        send_all(str, connfd);
        bzero(str, strlen(str));
      }
      else
      {
        tmp = g_clients;
        while (tmp != NULL)
        {
          connfd = tmp->fd;
          id = tmp->id;
          tmp = tmp->next;

          if (FD_ISSET(connfd, &set_read))
          {
            size = recv(connfd, buff, 1024, 0);
            if (size == 0)
            {
              id = rm_client(connfd);
              close(connfd);
              sprintf(str, "server: client %d just left\n", id);
              send_all(str, connfd);
            }
            else if (size > 0)
            {
              ex_msg(connfd, buff);
              bzero(buff, strlen(buff));
            }
          }
        }
      }
    }
  }
}
