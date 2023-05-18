#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>

typedef struct s_buffer {
  char* buf;
  int buf_size;
  struct s_buffer* next;
} t_buffer;

typedef struct s_client {
  int fd;
  int id;
  t_buffer* buffer;
  struct s_client* next;
} t_client;

void fatal() {
  char* msg = "Fatal error\n";
  write(2, msg, strlen(msg));
  exit(1);
}

void set_fd_max(int fd, int* fd_max) {
  if (fd > *fd_max)
    *fd_max = fd;
}

void send_to_all_clients(char* msg, t_client* clients) {

}

void add_client(int client_fd, int client_id, t_client* clients) {
  t_client* tmp = clients;
  t_client* new;
  t_buffer* new_buffer;
  
  if (!(new = (t_client*)malloc(sizeof(t_client))))
    fatal();
  if (!(new_buffer = (t_buffer*)malloc(sizeof(t_buffer))))
    fatal();
  new->fd = client_fd;
  new->id = client_id;
  new->next = NULL;
  new->buffer->buf = NULL;
  new->buffer->buf_size = 0;
  new->buffer->next = NULL;
  new->buffer = new_buffer;
  if (!clients)
    clients = new;
  else {
    while (tmp->next) 
      tmp = tmp->next;
    tmp->next = new;
  }
}

void accept_connect(int serv_fd, int* fd_max, int* client_id, t_client* clients) {
  struct sockaddr_in  client_addr;
  socklen_t len = sizeof(client_addr);
  int client_fd;
  char* msg;

  if ((client_fd = accept(serv_fd, (struct sockaddr *)&client_addr, &len)) == -1)
    fatal();
  set_fd_max(client_fd, fd_max);
  *client_id += 1;
  add_client(client_fd, *client_id, clients);
  sprintf(msg, "server: client %d just arrived\n", *client_id);
  send_to_all_clients(msg, clients);
}

void receive_data(int fd) {

}

void send_data(int fd) {

}

int main(int argc, char** argv) {
  int serv_fd;
  fd_set reads;
  fd_set writes;
  int fd_max = -1;
  int client_id = 0;
	struct sockaddr_in servaddr;
  int port;
  t_client* clients;

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

  while(1) {
    fd_set reads_cpy = reads;
    fd_set writes_cpy = writes;

    if (select(fd_max + 1, &reads_cpy, &writes_cpy, 0 , 0) == -1)
      fatal();

    for (int i = 0; i < fd_max; i++) {
      if (FD_ISSET(i, &reads_cpy)) {
        if (i == serv_fd)
          accept_connect(serv_fd, &fd_max, &client_id, clients);
        else {
          // receive data
        }

      }
      else if (FD_ISSET(i, &writes_cpy)) {
        // send data
      }
    }
  }

}
