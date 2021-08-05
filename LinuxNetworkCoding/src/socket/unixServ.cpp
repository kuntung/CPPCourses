#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/un.h> // UNIX域协议头文件
#define ERR_EXIT(m) \
    do {\
        perror(m); \
        exit(EXIT_FAILURE); \
       } while(0)
void echo_srv(int conn)
{
    char recvbuf[1024];
    while (1)
    {
        memset(recvbuf, 0, sizeof(recvbuf));

        int n = read(conn, recvbuf, sizeof(recvbuf));

        if (n == -1)
        {
            if (n == EINTR)
               continue;
            ERR_EXIT("echo_srv read");
            
        }
        else if (n == 0)
        {
            printf("client close\n");
            break;
        }

        fputs(recvbuf, stdout);
        write(conn, recvbuf, strlen(recvbuf));
    }

    close(conn);
}
int main(void)
{
    int listenfd;
    if ((listenfd = socket(PF_UNIX, SOCK_STREAM, 0)) < 0) // UNIX域中的流协议
        ERR_EXIT("main socket");

    unlink("test_socket"); // 避免服务器再次启动的时候，显示地址已使用
    struct sockaddr_un servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sun_family = AF_UNIX;
    strcpy(servaddr.sun_path, "test_socket");

    if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
        ERR_EXIT("main bind");

    if (listen(listenfd, SOMAXCONN) < 0)
        ERR_EXIT("main listen");

    int conn;
    pid_t pid;
    while (1)
    {
       conn = accept(listenfd, NULL, NULL); // 不关心对等方的地址
       if (conn == -1)
       {
            if (conn == EINTR)
                continue;
            ERR_EXIT("main while accept");
       }
       pid = fork();
       if (pid == -1)
       {
            ERR_EXIT("main fork");
       }

       if (pid == 0)
       {
            close(listenfd);
            echo_srv(conn);
            exit(EXIT_SUCCESS);
       }
       close(conn); // 父进程不需要处理已连接事件
    }

    return 0;
}
