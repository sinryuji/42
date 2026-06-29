#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <fcntl.h>

const int BUF_SIZE = 1024 * 96;

int main(int argc, char** argv) {
  int port = atoi(argv[1]);
  int sock_fd;
  int fd_max;

  struct sockaddr_in sockaddr;
  socklen_t len;

  if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    exit(1);

  fd_max = sock_fd;
  bzero(&sockaddr, sizeof(sockaddr));
  
	sockaddr.sin_family = AF_INET; 
	sockaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	sockaddr.sin_port = htons(port); 

  len  = sizeof(sockaddr);

	if (connect(sock_fd, (struct sockaddr*)&sockaddr, len) < 0)
    exit(1);
  
  fcntl(sock_fd, F_SETFL, O_NONBLOCK);
  fcntl(0, F_SETFL, O_NONBLOCK);

  char buf[BUF_SIZE + 1];

  fd_set reads;
  fd_set writes;

  FD_ZERO(&reads);
  FD_ZERO(&writes);
  FD_SET(sock_fd, &reads);
  FD_SET(0, &reads);

  struct timeval t;

  t.tv_sec = 1;
  t.tv_usec = 0;

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
        printf("disconect\n");
        exit(0);
      }
      else {
        buf[recv_size] = 0;
        printf("%s", buf);
      }
    }
    else if (FD_ISSET(0, &reads_cpy)) {
      int read_size = read(0, buf, BUF_SIZE);
      if (read_size < 0)
        exit(1);
      else {
        buf[read_size] = 0;
        FD_SET(sock_fd, &writes);
      }
    }
    else if (FD_ISSET(sock_fd, &writes_cpy)) {
      int len = strlen(buf);
      int send_size = send(sock_fd, buf, len, MSG_DONTWAIT);
      bzero(buf, BUF_SIZE + 1);
      FD_CLR(sock_fd, &writes);
    }
  }
}
