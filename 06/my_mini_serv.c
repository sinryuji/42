#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>

int serv_fd;
fd_set reads;
fd_set writes;
int fd_max = -1;

void fatal() {
  char* msg = "Fatal error\n";
  write(2, msg, strlen(msg));
  exit(1);
}

void set_fd_max(int fd) {
  if (fd > fd_max)
    fd_max = fd;
}

int main(int argc, char** argv) {
	struct sockaddr_in servaddr;
  int port;

  if (argc != 2) {
    char* msg = "Wrong number of arguments\n";
    write(2, msg, strlen(msg));
    exit(1);
  }
  
  port = atoi(argv[1]);
	serv_fd = socket(AF_INET, SOCK_STREAM, 0); 
	if (serv_fd == -1)
    fatal();
  set_fd_max(serv_fd);

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
      
      if (FD_IS_SET)

    }

  }

}
