//
// Created by jxq on 19-7-21.
//

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

#define ERR_EXIT(m) \
        do  \
        {   \
            perror(m);  \
            exit(EXIT_FAILURE); \
        } while(0);

ssize_t readn(int fd, void *buf, size_t count)
{
    size_t nleft = count;   // 剩余字节数
    ssize_t nread;
    char *bufp = (char*) buf;

    while (nleft > 0)
    {
        nread = read(fd, bufp, nleft);
        if (nread < 0)
        {
            if (errno == EINTR)
            {
                continue;
            }
            return  -1;
        } else if (nread == 0)
        {
            return count - nleft;
        }

        bufp += nread;
        nleft -= nread;
    }
    return count;
}

ssize_t writen(int fd, const void *buf, size_t count)
{
    size_t nleft = count;
    ssize_t nwritten;
    char* bufp = (char*)buf;

    while (nleft > 0)
    {
        if ((nwritten = write(fd, bufp, nleft)) < 0)
        {
            if (errno == EINTR)
            {
                continue;
            }
            return -1;
        }
        else if (nwritten == 0)
        {
            continue;
        }
        bufp += nwritten;
        nleft -= nwritten;
    }
    return count;
}

// recv_peek实现
ssize_t recv_peek(int sockfd, void *buf, size_t len)
{

    while (1)
    {
        int ret = recv(sockfd, buf, len, MSG_PEEK); // 从sockfd的套接字缓冲中peek长度为len的字符到buf中
        if (ret == -1 && errno == EINTR)
            continue;
        return ret;
    }
}

// readline实现
ssize_t readline(int sockfd, void *buf, size_t maxline)
{
    int ret;
    int nread;
    char *bufp = (char*)buf;
    int nleft = maxline;
    while (1)
    {
        ret = recv_peek(sockfd, bufp, nleft);
        if (ret < 0)
            return ret;
        else if (ret == 0)
            return ret;
        nread = ret;
        int i;
        for (i = 0; i < nread; ++i)
        {
            if (bufp[i] == '\n')
            {
                ret = readn(sockfd, bufp, i+1);
                if (ret != i+1)
                    exit(EXIT_FAILURE);

                return ret;
            }
        }
        if (nread > nleft)
            exit(EXIT_FAILURE);

        nleft -= nread;
        ret = readn(sockfd, bufp, nread);
        
        if (ret != nread)
            exit(EXIT_FAILURE);
        bufp += nread;

    }

    return -1;
}

void echo_cli(int sockfd)
{
// 4. 数据交换
    char recvbuf[1024];
    char sendbuf[1024];
    memset(recvbuf, 0, sizeof recvbuf);
    memset(sendbuf, 0, sizeof sendbuf);
    while (fgets(sendbuf, sizeof sendbuf, stdin) != NULL)   // 键盘输入获取
    {
       // writen(sockfd, sendbuf, strlen(sendbuf)); // 写入服务器
        write(sockfd, sendbuf, 1);
        write(sockfd, sendbuf + 1, strlen(sendbuf) - 1); // 分两次发送检测SIGPIPE
        int ret = readline(sockfd, recvbuf, sizeof(recvbuf));    // 服务器读取
        if (ret == -1)
        {
            ERR_EXIT("readline");
        }
        else if (ret == 0)
        {
            printf("server close\n");
            break;
        }
        fputs(recvbuf, stdout); // 服务器返回数据输出

        // 清空
        memset(recvbuf, 0, sizeof recvbuf);
        memset(sendbuf, 0, sizeof sendbuf);
    }

}
int main(int argc, char** argv) {
    // 1. 创建套接字
    int sockfd[5];
    int i;
    for (i = 0; i < 5; ++i)
    {
    if ((sockfd[i] = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        ERR_EXIT("socket");
    }

    // 2. 分配套接字地址
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof servaddr);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    // servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // inet_aton("127.0.0.1", &servaddr.sin_addr);

    // 3. 请求链接
    if (connect(sockfd[i], (struct sockaddr *) &servaddr, sizeof servaddr) < 0) {
        ERR_EXIT("connect");
    }
    // 获取本地地址
    struct sockaddr_in localaddr;
    socklen_t addrlen = sizeof localaddr;
    if (getsockname(sockfd[i], (sockaddr*)&localaddr, &addrlen) < 0)
        ERR_EXIT("getsockname");

    printf("ip = %s port = %d\n",inet_ntoa(localaddr.sin_addr), ntohs(localaddr.sin_port));
    struct sockaddr_in peeraddr;
    if (getpeername(sockfd[i], (sockaddr*)&peeraddr, &addrlen) < 0)
        ERR_EXIT("getpeername");

    printf("peer ip = %s port = %d \n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
    
    }
    // 为了逻辑简单，只让第一个套接字进行通信
    echo_cli(sockfd[0]);
    // 5. 断开连接
    close(sockfd[0]);


    return 0;
}
