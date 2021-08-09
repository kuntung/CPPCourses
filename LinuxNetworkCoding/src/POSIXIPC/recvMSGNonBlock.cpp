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

    mqd_t mqid;

    mqid = mq_open("/abc", O_RDONLY);

    if (mqid == (mqd_t)-1)
    {
        ERR_EXIT("main mq_open");
    }

    // 获取消息队列的长度
    struct mq_attr attr;
    mq_getattr(mqid, &attr);

    STU stu;
    unsigned prio; 
    int ret;
    ret = mq_receive(mqid, (char*)&stu, attr.mq_msgsize, &prio);
    if (ret == (mqd_t)-1)
    {
        ERR_EXIT("main mq_recv");
    }
    printf("mq_receive success\n");
    printf("stu.name = %s, stu.age = %d\n", stu.name, stu.age);
    mq_close(mqid); // 关闭消息队列
    return 0;
}
