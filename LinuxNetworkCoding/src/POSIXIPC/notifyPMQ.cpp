#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h> // 消息队列头文件
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m) \
    do{ \
        perror(m); \
        exit(EXIT_FAILURE); \
      } while (0)

typedef struct stu
{
    char name [32];
    int age;
} STU;

size_t size;
mqd_t mqid;
struct sigevent sigev;

void handle_sigusr1(int sig)
{
    mq_notify(mqid, &sigev); // 注册事件 
    // 获取消息队列的长度

    STU stu;
    unsigned prio; 
    int ret;
    ret = mq_receive(mqid, (char*)&stu, size, &prio);
    if (ret == (mqd_t)-1)
    {
        ERR_EXIT("main mq_recv");
    }
    printf("mq_receive success\n");
    printf("stu.name = %s, stu.age = %d\n", stu.name, stu.age);


}

int main(int argc, char *argv[])
{
    mqid = mq_open("/abc", O_RDONLY);

    // 获取最大消息的长度
    struct mq_attr attr;
    mq_getattr(mqid, &attr);
    size = attr.mq_msgsize;

    if (mqid == (mqd_t)-1)
    {
        ERR_EXIT("main mq_open");
    }

    signal(SIGUSR1, handle_sigusr1); // 信号通知
    
    sigev.sigev_notify = SIGEV_SIGNAL; // 以信号通知
    sigev.sigev_signo = SIGUSR1;
 
    for(;;)
        pause(); // 死循环接受处理

    mq_close(mqid); // 关闭消息队列
    return 0;
}
