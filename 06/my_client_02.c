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
  char buf[100001];
  for (int i = 0; i < 100000; i++)
    buf[i] = 'a';
  buf[100000]  = 0;
  send(sock_fd, buf, 100000, 0);
  sleep(5);
  
  char buf2[11];
  for (int i = 0; i < 9; i++)
    buf2[i] = 'b';
  buf2[9] = '\n';
  buf2[10] = 0;
  send(sock_fd, buf2, 10, 0);

  while(1)
    sleep(1);

}
