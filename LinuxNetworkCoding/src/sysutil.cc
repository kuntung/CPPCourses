#include "LinuxNetworkCoding/src/sysutil.h"

void activate_nonblock(int fd)
{
    int ret;
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1)
        ERR_EXIT("fcntl");
    
    flags |= O_NONBLOCK;
    
    ret = fcntl(fd, F_SETFL, flags);
    if (ret == -1)
        ERR_EXIT("fcntl");
}

void deactivate_nonblock(int fd)
{
    int ret;
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1)
        ERR_EXIT("fcntl");
    
    flags &= ~O_NONBLOCK;
    
    ret = fcntl(fd, F_SETFL, flags);
    if (ret == -1)
        ERR_EXIT("fcntl");
}

// connect_timeout实现
int connect_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds)
{
    int ret;
    socklen_t addrlen = sizeof(struct sockaddr_in);
    
    if (wait_seconds > 0)
    {
        activate_nonblock(fd);
	}
    
    ret = connect(fd, (struct sockaddr*)&addr, addrlen);
    
    if (ret < 0 && errno == EINPROGRESS)
    {
        fd_set connect_fdset;
        struct timeval timeout;
        FD_ZERO(&connect_fdset);
        FD_SET(fd, &connect_fdset);
        timeout.tv_sec = wait_seconds;
        timeout.tv_usec = 0;
    
    do
    {
        ret = select(fd + 1, NULL, &connect_fdset, NULL, &timeout);
    } while (ret < 0 && errno == EINTR);
    
    if (ret == 0) // 超时
    {
        ret = -1;
        errno = ETIMEDOUT;
    }
    else if (ret < 0) // 发生错误
    {
        return -1;
    }
    else if (ret == 1)
    {
        int err;
        socklen_t socklen = sizeof(err);
        int sockoptret = getsockopt(fd, SOL_SOCKET, SO_ERROR, &err, &socklen);
        if (sockoptret == -1) // 调用出错
        {
            return -1;
        }
        else if (err == 0)
        {
            ret = 0;
        }
        else // 套接字发生错误
        {
            errno = err;
            ret = -1;
        }
    }
    }
    if (wait_seconds > 0)
    {
        deactivate_nonblock(fd);
    }
    
    return ret;
}