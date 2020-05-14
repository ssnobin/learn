#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
int main(int argc, const char *argv[]) {
    
    // create
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket error");
        exit(-1);
    }
    
    //connect
    struct sockaddr_in c_addr;
    bzero(&c_addr, sizeof(c_addr));
    c_addr.sin_family = AF_INET;
    c_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &c_addr.sin_addr.s_addr);
    
    int ret = connect(fd, (struct sockaddr*)&c_addr, sizeof(c_addr));
    if (ret == -1) {
        perror("connect error");
        exit(-1);
    }
    
    while(1) {
        //
        char buf[1024] = {0};
        fgets(buf, sizeof(buf), stdin);
        write(fd, buf, strlen(buf));
        //接收, 阻塞等待
        int len = read(fd, buf, sizeof(buf));
        if (len == -1) {
             perror("read error");
             exit(-1);
        }
        printf("client recv %s\n", buf);
        
    }
    
    close(fd);
     return 0;
}