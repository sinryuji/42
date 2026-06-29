#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_client {
  int fd;
  int id;
} client;

fd_set g_reads;
fd_set g_writes;
int    g_fd_max = 0;
int    g_client_id = -1;
client client_list[1024];
char buf[1000000];
char msg[1000000];

void fatal() {
  char* msg = "Fatal error\n";
  write(2, msg, strlen(msg));
  exit(1);
}

void set_fd_max(int fd) {
  if (fd > g_fd_max)
    g_fd_max = fd;
}

void send_all(int fd) {
  for (int i = 0; i < 1024; i++) {
    if (client_list[i].fd != fd)
     send(client_list[i].fd, msg, strlen(msg), 0) ;
  }
  bzero(msg, strlen(msg));
}

void accept_connection(int fd) {
	struct sockaddr_in cli;
  socklen_t len = sizeof(cli);
  int client_fd;
  int id;

	client_fd = accept(fd, (struct sockaddr *)&cli, &len);
  if (client_fd == -1)
    return;
  set_fd_max(client_fd);
  FD_SET(client_fd, &g_reads);
  g_client_id++;
  id = g_client_id;
  client_list[client_fd].fd = client_fd;
  client_list[client_fd].id = id;
  sprintf(msg, "server: client %d just arrived\n", id);
  send_all(client_fd);
}

void receive_data(int fd) {
  int recv_size = recv(fd, buf, 99999, 0);
  if (recv_size <= 0) {
    sprintf(msg, "server: client %d just left\n", client_list[fd].id);
    send_all(fd);
    client_list[fd].fd = -1;
    client_list[fd].id = -1;
    FD_CLR(fd, &g_reads);
    close(fd);
  }
  else {
    buf[recv_size] = 0;
    if (strstr(buf, "\n")) {
      int i = 0;
      int j = 0;
      char tmp[1000000];
      while (buf[i]) {
        tmp[j++] = buf[i];
        if (buf[i] == '\n') {
          tmp[j] = 0;
          sprintf(msg, "client %d: %s", client_list[fd].id, tmp);
          send_all(fd);
          j = 0;
        }
        ++i;
      }
    }
    bzero(buf, 1000000);
  }
}

int main(int argc, char **argv) {
  int port;
	struct sockaddr_in servaddr;
  int serv_fd;
  struct timeval t;

  if (argc != 2) {
    char* msg = "Wrong number of arguments\n";
    write(2, msg, strlen(msg));
    exit(1);
  }

	if ((serv_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    fatal();

  FD_ZERO(&g_reads);
  FD_ZERO(&g_writes);
  set_fd_max(serv_fd);
  fcntl(serv_fd, F_SETFL, O_NONBLOCK);
  FD_SET(serv_fd, &g_reads);

	bzero(&servaddr, sizeof(servaddr));
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

    if (select(g_fd_max + 1, &reads_cpy, &writes_cpy, 0, &t) == -1) {
      printf("break?");
      break;
    }
    
    for (int i = 0; i < g_fd_max + 1; i++) {
      if (FD_ISSET(i, &reads_cpy)) {
        if (i == serv_fd)
          accept_connection(i);
        else
          receive_data(i);
      }
    }
  }
}
