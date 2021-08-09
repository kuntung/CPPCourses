#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h> // 消息队列头文件
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define ERR_EXIT(m) \
    do{ \
        perror(m); \
        exit(EXIT_FAILURE); \
      } while (0)

int main(void)
{
    mqd_t mqid;

    mqid = mq_open("/abc", O_RDONLY);

    if (mqid == (mqd_t)-1)
    {
        ERR_EXIT("main mq_open");
    }

    printf("mq_open success\n");
    struct mq_attr oldattr;
    
    mq_getattr(mqid, &oldattr);
    printf("before set : mq_maxmsg = %ld mq_maxbytes = %ld #currently on queue = %ld\n",oldattr.mq_maxmsg, oldattr.mq_msgsize, oldattr.mq_curmsgs);
    // 消息队列属性设置
    struct mq_attr newattr;
    newattr.mq_maxmsg = 4; 
    newattr.mq_msgsize = 65535;
    newattr.mq_curmsgs = 0;
    mq_setattr(mqid, &newattr, &oldattr);
    printf("after set : mq_maxmsg = %ld mq_maxbytes = %ld #currently on queue = %ld\n",newattr.mq_maxmsg, newattr.mq_msgsize , newattr.mq_curmsgs);
    mq_close(mqid); // 关闭消息队列
    return 0;
}
