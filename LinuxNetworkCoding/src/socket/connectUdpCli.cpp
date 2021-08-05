#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <netinet/in.h>


#define ERR_EXIT(m)\
    do \
    { \
        perror(m); \
        exit(EXIT_FAILURE);\
    } while(0)

void echo_cli(int sock)
{
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr));
    
    // 获取本机和对等方地址

    int ret;
    char sendbuf[1024] = {0};
    char recvbuf[1024] = {0};

    while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
    {
       // sendto(sock, sendbuf, strlen(sendbuf), 0, NULL, NULL);
        send(sock, sendbuf, strlen(sendbuf), 0); // 对于调用了connect的udp套接字，可以采用send/write 
        ret = recvfrom(sock, recvbuf, sizeof(recvbuf), 0, NULL, NULL);

        if (ret == -1)
        {
            if (errno == EINTR)
                continue;
            ERR_EXIT("recvfrom");
        }

        fputs(recvbuf, stdout);
        memset(recvbuf, 0, sizeof(recvbuf));
        memset(sendbuf, 0, sizeof(sendbuf));

    }

    close(sock);

}
int main(void)
{
    int sock;
    if ((sock = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
        ERR_EXIT("SOCKET");

    echo_cli(sock);

    return 0;
}

