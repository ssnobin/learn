#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netdb.h>
//#include <netinet/in.h>
int main(int argc, const char *argv[]) {
    
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo("127.0.0.1", "8080", &hints, &res);

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    connect(sockfd, res->ai_addr, res->ai_addrlen);

    close(sockfd);
    return 0;
}