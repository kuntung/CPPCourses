#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <netinet/in.h>
#define ERR_EXIT(m) \
    do \
    { \
        perror(m); \
        exit(EXIT_FAILURE);\
    } while(0)

int main(void)
{
    int listenfd;
    if ((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0 )
        ERR_EXIT("SOCKET");

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5188);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
   // servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // inet_aton("127.0.0,1", &servaddr.sin_addr);

    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
        ERR_EXIT("setsockopt");
    if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
        ERR_EXIT("BIND");
    
    if (listen(listenfd, SOMAXCONN) < 0) // 队列的最大值
        ERR_EXIT("LISTEN");

    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);
    int conn = 0;
    if (conn = accept(listenfd, (struct sockaddr*)&peeraddr, &peerlen) < 0)
        ERR_EXIT("ACCEPT");

    char recvbuf[1024];
    while (1)
    {
        memset(recvbuf, 0, sizeof(recvbuf));
        int res = read(conn, recvbuf, sizeof(recvbuf));
        fputs(recvbuf, stdout);
        write(conn, recvbuf, res);
    }
    close(conn);
    close(listenfd);
    return 0;
}
