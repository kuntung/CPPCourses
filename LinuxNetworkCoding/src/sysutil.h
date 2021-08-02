#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define ERR_EXIT(m) \
    do \
    { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while (0)


// 设置I/O为非阻塞模式
void activate_nonblock(int fd);
// 设置I/O为阻塞模式
void deactivate_nonblock(int fd);

// connect_timeout实现
int connect_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds);


