#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <fcntl.h>

const int BUF_SIZE = 65536;

typedef struct s_buffer {
  char* buf;
  int buf_size;
} t_buffer;

typedef struct s_msg {
  char* msg;
  struct s_msg* next;
} t_msg;

typedef struct s_client {
  int fd;
  int id;
  t_buffer* recv_buf;
  t_buffer* send_buf;
  t_msg* queue;
  struct s_client* next;
} t_client;

t_client* clients = NULL;
fd_set reads;
fd_set writes;

void fatal() {
  char* msg = "Fatal error\n";
  write(2, msg, strlen(msg));
  exit(1);
}

void set_fd_max(int fd, int* fd_max) {
  if (fd > *fd_max)
    *fd_max = fd;
}

char* ft_strdup(char* str) {
  char* ret;
  int len;

  if (!str)
    return NULL;
  len = strlen(str);
  ret = (char*)malloc(sizeof(char) * (len + 1));
  if (!ret)
    return NULL;
  strcpy(ret, str);
  return ret;
}

void ft_strcat(char* str1, char* str2) {
  char* tmp = ft_strdup(str1);

  if (!(str1 = (char*)realloc(str1, sizeof(char) * (strlen(str1) + strlen(str2) + 1))))
    fatal();
  strcpy(str1, tmp);
  strcat(str1, str2);;
}

char* ft_substr(char* str, int n) {
  char* ret;
  int i;

  if(!(ret = (char*)malloc(sizeof(char) * n)))
    fatal();
  
  i = 0;
  while (i < n) {
    ret[i] = str[i];
    i++;
  }
  ret[i] = 0;

  char* tmp = ft_strdup(str);
  free(str);
  if (!(str = (char*)malloc(sizeof(char) * (strlen(str) - n))))
    fatal();
  i = n + 1;
  int str_i = 0;
  while (tmp[i]) {
    str[str_i] = tmp[i];
    str_i++;
    i++;
  }
  str[str_i] = 0;
  
  return ret;
}

void send_to_all_clients(char* msg, fd_set* writes) {
  t_client* tmp = clients;

  while (tmp) {
    if (tmp->send_buf->buf != NULL)
      free(tmp->send_buf->buf);
    tmp->send_buf->buf = ft_strdup(msg);
    tmp->send_buf->buf_size = strlen(msg);
    FD_SET(tmp->fd, writes);
    tmp = tmp->next;
  }
}

void init_buffer(t_client* client) {
  t_buffer* recv_buf;
  t_buffer* send_buf;

  if (!(recv_buf = (t_buffer*)malloc(sizeof(t_buffer))))
    fatal();
  if (!(send_buf = (t_buffer*)malloc(sizeof(t_buffer))))
    fatal();

  recv_buf->buf = NULL;
  recv_buf->buf_size = 0;

  send_buf->buf = NULL;
  send_buf->buf_size = 0;

  client->recv_buf = recv_buf;
  client->send_buf = send_buf;
}

void add_client(int client_fd, int client_id) {
  t_client* tmp = clients;
  t_client* new;

  if (!(new = (t_client*)malloc(sizeof(t_client))))
    fatal();
  new->fd = client_fd;
  new->id = client_id;
  new->next = NULL;
  init_buffer(new);
  if (!clients)
    clients = new;
  else {
    while (tmp->next) 
      tmp = tmp->next;
    tmp->next = new;
  }
}

void accept_connect(int serv_fd, int* fd_max, int* client_id, fd_set* writes) {
  struct sockaddr_in  client_addr;
  socklen_t len = sizeof(client_addr);
  int client_fd;
  char msg[BUF_SIZE];

  if ((client_fd = accept(serv_fd, (struct sockaddr *)&client_addr, &len))) {
    fcntl(client_fd, F_SETFL, O_NONBLOCK);
    set_fd_max(client_fd, fd_max);
    FD_SET(client_fd, &reads);
    *client_id += 1;
    add_client(client_fd, *client_id);
    sprintf(msg, "server: client %d just arrived\n", *client_id);
    send_to_all_clients(msg, writes);
  }
}

t_client* get_client(int fd) {
  t_client* tmp = clients;

  while (tmp) {
    if (tmp->fd == fd)
      return tmp;
    tmp = tmp->next;
  }

  return NULL;
}

void add_recv_buf(int fd, char* data) {
  t_buffer* buf = get_client(fd)->recv_buf;
  if (!buf->buf) {
    if (!(buf->buf = (char*)malloc(sizeof(char) * (strlen(data) + 1))))
        fatal();
    strcpy(buf->buf, data);
  }
  else {
    char* tmp = ft_strdup(buf->buf);
    free(buf->buf);
    if (!(buf->buf = malloc(strlen(tmp) + strlen(data) + 1)))
      fatal();
    strcpy(buf->buf, tmp);
    strcat(buf->buf, data);
  }
}

void add_queue(int fd, char* msg) {
  t_msg* new;
  t_client* cli = get_client(fd);

  if (!(new = (t_msg*)malloc(sizeof(t_msg))))
    fatal();
  new->msg = ft_strdup(msg);

  if (!cli->queue) {
    cli->queue = new;
  }
  else {
    t_msg* tmp = cli->queue;
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = new;
  }

}

void parse_recv(int fd) {
  int i = 0;
  char* line;
  t_buffer* buf = get_client(fd)->recv_buf;

  while(buf->buf[i]) {
    if (buf->buf[i] == '\n') {
      line = ft_substr(buf->buf, i);
      add_queue(fd, line);
      free(line);
      i = 0;
      continue;
    }
    i++;
  }
}

void remove_queue(int fd) {
  t_client* cli = get_client(fd);
  t_msg* tmp = cli->queue;
  cli->queue = cli->queue->next;
  free(tmp->msg);
  free(tmp);
}

void clean_client(t_client* client, fd_set* reads) {
  t_msg* queue = client->queue;
  t_msg* tmp;
  
  while (queue) {
    tmp = queue;
    queue = queue->next;
    free(tmp->msg);
    free(tmp);
  }
  FD_CLR(client->fd, reads);
  free(client->recv_buf);
  free(client->send_buf);
  free(client);
}

void remove_client(int fd, fd_set* reads) {
  char msg[BUF_SIZE];
  t_client* tmp = clients;
  t_client* tmp2;
  int flag = 0;

  sprintf(msg, "server: client %d just left\n", get_client(fd)->id);

  if (tmp && tmp->fd == fd) {
    clients = tmp->next;
    clean_client(tmp, reads);
    flag = 1;
  }
  else {
    while (tmp && tmp->next) {
      if (tmp->next->fd == fd) {
        tmp2 = tmp->next;
        tmp->next = tmp->next->next;
        clean_client(tmp2 ,reads);
        flag = 1;
      }
      tmp = tmp->next;
    }
  }
}

void send_msg(t_client* clients, fd_set* writes) {
  t_client* tmp = clients;
  char msg[BUF_SIZE];

  while (tmp) {
    if (tmp->queue) {
      sprintf(msg, "client %d: %s\n", tmp->id, tmp->queue->msg);
      send_to_all_clients(msg, writes);
      remove_queue(tmp->fd);
      break;
    }
    tmp = tmp->next;
  }
}

void receive_data(int fd, fd_set* reads, fd_set* writes) {
  char buf[BUF_SIZE + 1];
  char msg[BUF_SIZE];
  int recv_size;
  t_client* client;
  
  recv_size = recv(fd, buf, BUF_SIZE, MSG_DONTWAIT);
  if (recv_size <= 0)
    remove_client(fd, reads);
  buf[recv_size ] = 0;
  client = get_client(fd);
  client->recv_buf->buf_size += recv_size;
  add_recv_buf(fd, buf);
  parse_recv(fd);
  
  if (client->queue) {
    sprintf(msg, "client %d: %s\n", client->id, client->queue->msg);
    send_to_all_clients(msg, writes);
    remove_queue(fd);
  }
}

void send_data(int fd, fd_set* reads, fd_set* writes) {
  int send_size;
  t_client* client = get_client(fd);

  send_size = send(fd, client->send_buf->buf, client->send_buf->buf_size, MSG_DONTWAIT);
  if (send_size <= 0)
    remove_client(fd, reads);
  if (send_size == client->send_buf->buf_size) {
//    if (client->send_buf->buf != NULL)
//      free(client->send_buf->buf);
    client->send_buf->buf_size = 0;
    FD_CLR(fd, writes);
  }
  else {
    ft_substr(client->send_buf->buf, send_size);
    client->send_buf->buf_size -= send_size;
  }
}

int main(int argc, char** argv) {
  int serv_fd;
  int fd_max = -1;
  int client_id = 0;
  struct sockaddr_in servaddr;
  int port;
  struct timeval t;

  if (argc != 2) {
    char* msg = "Wrong number of arguments\n";
    write(2, msg, strlen(msg));
    exit(1);
  }

  port = atoi(argv[1]);
  serv_fd = socket(AF_INET, SOCK_STREAM, 0); 
  if (serv_fd == -1)
    fatal();
  set_fd_max(serv_fd, &fd_max);

  bzero(&servaddr, sizeof(servaddr)); 

  servaddr.sin_family = AF_INET; 
  servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
  servaddr.sin_port = htons(port); 

  if ((bind(serv_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
    fatal();
  if (listen(serv_fd, 16) < 0)
    fatal();

  FD_ZERO(&reads);
  FD_ZERO(&writes);
  FD_SET(serv_fd, &reads);

  t.tv_sec = 1;
  t.tv_usec = 0;

  while(1) {
    fd_set reads_cpy = reads;
    fd_set writes_cpy = writes;

    send_msg(clients, &writes);

    if (select(fd_max + 1, &reads_cpy, &writes_cpy, 0 , &t) == -1)
      break;

    for (int i = 0; i < fd_max + 1; i++) {
      if (FD_ISSET(i, &reads_cpy)) {
        if (i == serv_fd) {
          accept_connect(i, &fd_max, &client_id, &writes);
        }
        else
          receive_data(i, &reads, &writes);
      }
      else if (FD_ISSET(i, &writes_cpy)) {
        send_data(i, &reads, &writes);
      }
    }
  }

}
