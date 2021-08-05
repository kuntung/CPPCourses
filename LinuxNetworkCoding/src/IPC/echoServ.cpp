#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m)\
    do{\
        perror(m);\
        exit(EXIT_FAILURE);\
      } while(0)

#define MSGMAX 65536

// echoserv
void echo_srv(int msgid)
{
    struct msgbuf msg;
    memset(&msg, 0, sizeof(msg));
    while (1)
    {
            int n = 0;
            if ((n = msgrcv(msgid, &msg, MSGMAX, 1, 0)) < 0) // 非阻塞模式
                ERR_EXIT("main msgrcv");
            int pid; // 获得进程ID
            pid = *((int*)msg.mtext);
            
            fputs(msg.mtext + 4, stdout);
            msg.mtype = pid;
            msgsnd(msgid, &msg, n, 0);
    }
}


int main(int argc, char *argv[])
{
    int msgid;
    msgid = msgget(1234, IPC_CREAT | 0666);
    if (msgid == -1)
        ERR_EXIT("msgget");
    echo_srv(msgid); 

    return 0;
}
