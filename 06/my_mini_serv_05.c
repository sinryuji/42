#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

const int BUF_SIZE = 1024 * 128;

typedef struct s_client {
  int fd;
  int id;
  char* recv_buf;
  char* send_buf;
  struct s_client* prev;
  struct s_client* next;
} client;

fd_set  g_reads;
fd_set  g_writes;
int     g_fd_max = 0;
int     g_client_id = -1;
client* g_client_list = NULL;

void fatal() {
  char* msg = "Fatal error\n";
  write(2, msg, strlen(msg));
  exit(1);
}

void set_fd_max(int fd) {
  if (fd > g_fd_max)
    g_fd_max = fd;
}

char* ft_substr(char* str) {
  char* ret;

  if (!(ret = malloc(sizeof(char) * (strlen(str) + 1))))
    fatal();
  if (!str)
    return NULL;
  
  int i = 0;
  while (str[i]) {
    ret[i] = str[i];
    i++;
  }
  ret[i] = 0;

  return ret;
}

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void send_all(char* msg, int fd) {
  client* tmp = g_client_list;

  while (tmp) {
    if (tmp->fd != fd) {
      if (tmp->send_buf) {
        free(tmp->send_buf);
        tmp->send_buf = NULL;
      }
      tmp->send_buf = ft_substr(msg);
      FD_SET(tmp->fd, &g_writes);
    }
    tmp = tmp->next;
  }
}

void print_client_list() {
  client* tmp = g_client_list;

  printf("===== client list =====\n");
  while (tmp) {
    printf("id : %d\n", tmp->id);
    tmp = tmp->next;
  }
}

void add_client(int fd, int id) {
  client* new;

  if (!(new = malloc(sizeof(client))))
    fatal();
  
  new->fd = fd;
  new->id = id;
  new->recv_buf = NULL;
  new->send_buf = NULL;
  new->prev = NULL;
  new->next = NULL;

  if (g_client_list == NULL)
    g_client_list = new;
  else {
    client* tmp = g_client_list;
    while (tmp->next)
      tmp = tmp->next;
    new->prev = tmp;
    tmp->next = new;
  }
}

client* get_client(int fd) {
  client* tmp = g_client_list;

  while (tmp) {
    if (tmp->fd == fd)
      return tmp;
    tmp = tmp->next;
  }

  return NULL;
}

void remove_client(int fd) {
  client* tmp = g_client_list;
  int client_fd = -1;
  int client_id = -1;
  char msg[128];

  while (tmp) {
    if (tmp->fd == fd) {
      if (tmp->prev)
        tmp->prev->next = tmp->next;
      if (tmp->next)
        tmp->next->prev = tmp->prev;
      if (!tmp->prev && !tmp->next)
        g_client_list = NULL;
      if (!tmp->prev && tmp->next)
        g_client_list = tmp->next;
      if (tmp->recv_buf)
        free(tmp->recv_buf);
      if (tmp->send_buf)
        free(tmp->send_buf);
      client_fd = tmp->fd;
      client_id = tmp->id;
      free(tmp);
//      close(client_fd);
      FD_CLR(client_fd, &g_reads);
      sprintf(msg, "server: client %d just left\n", client_id);
      send_all(msg, client_fd);
      break;
    }
    tmp = tmp->next;
  }
}

void accept_connection(int fd) {
	struct sockaddr_in cli;
  int client_fd;
  int id;
  socklen_t len = sizeof(cli);
  char msg[128];

	client_fd = accept(fd, (struct sockaddr *)&cli, &len);
  if (client_fd == -1)
    return;
  g_client_id++;
  id = g_client_id;
  fcntl(client_fd, F_SETFL, O_NONBLOCK);
  FD_SET(client_fd, &g_reads);
  set_fd_max(client_fd);
  add_client(client_fd, id);
  sprintf(msg, "server: client %d just arrived\n", id);
  send_all(msg, client_fd);
}

char* parse_recv(int fd) {
  char* line = NULL;
  char msg[BUF_SIZE * 2];
  client* client = get_client(fd);
  char* ret = NULL;

  while (extract_message(&client->recv_buf, &line)) {
    sprintf(msg, "client %d: %s", client->id, line);
    ret = str_join(ret, msg);
    free(line);
  }

  return ret;
}

void receive_data(int fd) {
  int recv_size;
  char buf[BUF_SIZE + 1];
  client* client = get_client(fd);

  recv_size = recv(fd, buf, BUF_SIZE, MSG_DONTWAIT);
  if (recv_size <= 0)
    remove_client(fd);
  else {
    client->recv_buf = str_join(client->recv_buf, buf);
    char* msg = NULL;
    msg = parse_recv(fd);
    if (msg != NULL) {
      send_all(msg, fd);
      free(msg);
    }
  }
}

void send_data(int fd) {
  int send_size;;
  client* client = get_client(fd);
  int len = strlen(client->send_buf);

  send_size = send(fd, client->send_buf, len, MSG_DONTWAIT);
  if (send_size <= 0)
    remove_client(fd);
  else if (send_size == len) {
    free(client->send_buf);
    client->send_buf = NULL;
    FD_CLR(client->fd, &g_writes);
  }
}

int main(int argc, char** argv) {
  int port;
  int serv_fd;
	struct sockaddr_in servaddr;
  struct timeval t;

  if (argc != 2) {
    char* msg = "Wrong number of arguments\n";
    write(2, msg, strlen(msg));
    exit(1);
  }

	if ((serv_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    fatal();

	bzero(&servaddr, sizeof(servaddr)); 
  set_fd_max(serv_fd);
  FD_ZERO(&g_reads);
  FD_ZERO(&g_writes);
  FD_SET(serv_fd, &g_reads);

  port = atoi(argv[1]);
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 

	if ((bind(serv_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
    fatal();
	if (listen(serv_fd, 128) != 0)
    fatal();

  t.tv_sec = 1;
  t.tv_usec = 0;

  while (1) {
    fd_set reads_cpy = g_reads;
    fd_set writes_cpy = g_writes;

    if (select(g_fd_max + 1, &reads_cpy, &writes_cpy, 0, &t) == -1)
      break;

    for (int i = 0; i < g_fd_max + 1; i++) {
      if (FD_ISSET(i, &reads_cpy)) {
        if (i == serv_fd)
          accept_connection(i);
        else
          receive_data(i);
      }
      else if (FD_ISSET(i, &writes_cpy))
        send_data(i);
    }
  }
}
