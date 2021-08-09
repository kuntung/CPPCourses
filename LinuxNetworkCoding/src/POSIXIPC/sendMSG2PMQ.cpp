#include <unistd.h>
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
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <prio> \n", argv[1]);
        exit(EXIT_FAILURE);
    }
    mqd_t mqid;

    mqid = mq_open("/abc", O_WRONLY);

    if (mqid == (mqd_t)-1)
    {
        ERR_EXIT("main mq_open");
    }


    STU stu;
    strcpy(stu.name, "test");
    stu.age = 20;

    unsigned prio = atoi(argv[1]);
    int ret;
    ret = mq_send(mqid, (const char*)&stu, sizeof(STU), prio);
    if (ret == -1)
    {
        if (errno == EAGAIN)
        {
            printf("queue is full. send fail...\n");
        }
    }
    printf("mq_send success\n");
    mq_close(mqid); // 关闭消息队列
    return 0;
}
