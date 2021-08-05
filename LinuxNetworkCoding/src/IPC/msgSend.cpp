#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define ERR_EXIT(m)\
    do{\
        perror(m);\
        exit(EXIT_FAILURE);\
      } while(0)

// 消息结构体

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <bytes> <type> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int len = atoi(argv[1]);
    int type = atoi(argv[2]);
    int msgid;
    msgid = msgget(1234, 0); 

    if (msgid == -1)
        ERR_EXIT("msgget");
    
    struct msgbuf *ptr;
    ptr =(struct msgbuf*)malloc(sizeof(long) + 1);
    ptr->mtype = type;
    msgsnd(msgid, ptr, len, IPC_NOWAIT); // 非阻塞模式

    return 0;
}
