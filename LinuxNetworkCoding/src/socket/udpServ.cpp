#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>


#define ERR_EXIT(m)\
    do \
    { \
        perror(m); \
        exit(EXIT_FAILURE);\
    } while(0)

void test(int sock, struct sockaddr_in* peeraddr, char *recvbuf, int n)
{
    sendto(sock, recvbuf, n, 0, (struct sockaddr*)peeraddr, sizeof(peeraddr));
}
void echo_srv(int sock)
{
    char recvbuf[1024] = {0};
    struct sockaddr_in peeraddr;
    socklen_t peerlen;

    int n;
    while (1)
    {
        peerlen = sizeof(peeraddr);
        memset(recvbuf, 0, sizeof(recvbuf));

        n = recvfrom(sock, recvbuf, sizeof(recvbuf), 0, (struct sockaddr*)&peeraddr, &peerlen);

        if (n == -1)
        {
            if (errno == EINTR)
                continue;
            ERR_EXIT("RECVFROM");
        }
        
        else if (n > 0)
        {
            fputs(recvbuf, stdout);
            sendto(sock, recvbuf, n, 0, (struct sockaddr*)&peeraddr, peerlen);
        }
    }
    close(sock);
}
int main(void)
{
    int sock;
    if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
        ERR_EXIT("SOCKET");

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof servaddr);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr*)&servaddr, (socklen_t)sizeof(servaddr)) < 0 )
    {
        ERR_EXIT("BIND");
    }


    echo_srv(sock);

    return 0;
}

