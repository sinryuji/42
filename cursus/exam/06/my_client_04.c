#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char** argv) {
  int port;
  int sock_fd;
	struct sockaddr_in cli;
  struct timeval t;
  int fd_max;

  if (argc != 2) {
    char* tmp = "Wrong number of arguments\n";
    write(2, tmp, strlen(tmp));
    exit(1);
  }
  
  port = atoi(argv[1]);

	if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    exit(1);
  fd_max = sock_fd;

	cli.sin_family = AF_INET; 
	cli.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	cli.sin_port = htons(port); 

	if (connect(sock_fd, (const struct sockaddr *)&cli, sizeof(cli)) < 0)
    exit(1);

  fd_set reads;
  fd_set writes;
  
  FD_ZERO(&reads);
  FD_ZERO(&writes);
  FD_SET(sock_fd, &reads);
  FD_SET(0, &reads);
  fcntl(sock_fd, F_SETFL, O_NONBLOCK);
  fcntl(0, F_SETFL, O_NONBLOCK);

  t.tv_sec = 1;
  t.tv_usec = 0;

  int BUF_SIZE = 1024 * 128;
  char buf[BUF_SIZE + 1];
  bzero(buf, BUF_SIZE + 1);

  while (1) {
    fd_set reads_cpy = reads;
    fd_set writes_cpy = writes;

    if (select(fd_max + 1, &reads_cpy, &writes_cpy, 0, &t) == -1)
      break;

    if (FD_ISSET(sock_fd, &reads_cpy)) {
      int recv_size = recv(sock_fd, buf, BUF_SIZE, MSG_DONTWAIT);
      if (recv_size < 0)
        exit(1);
      else if (recv_size == 0) {
        printf("disconnect\n");
        exit(0);
      }
      else {
        buf[recv_size] = 0;
        printf("%s", buf);
        bzero(buf, BUF_SIZE + 1);
      }
    }
    else if (FD_ISSET(0, &reads_cpy)) {
      int read_size = read(0, buf, BUF_SIZE);
      if (read_size <= 0)
        exit(1);
      else
        FD_SET(sock_fd, &writes);
    }
    else if (FD_ISSET(sock_fd, &writes_cpy)) {
      int len = strlen(buf);
      int send_size = send(sock_fd, buf, len, MSG_DONTWAIT);
      if (send <= 0)
        exit(1);
      else {
        bzero(buf, BUF_SIZE + 1);
        FD_CLR(sock_fd, &writes);
      }
    }
  }
}
