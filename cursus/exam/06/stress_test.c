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

  for (int i = 0; i < 10000; i++) {
	  if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
      exit(1);
    if (connect(sock_fd, (const struct sockaddr *)&cli, sizeof(cli)) < 0)
      exit(1);
    close(sock_fd);
    usleep(10);
  }

}
