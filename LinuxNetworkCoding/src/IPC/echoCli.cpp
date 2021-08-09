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

// 消息结构体
#define MSGMAX 65535


void echo_cli(int msgid)
{
    struct msgbuf msg;
    int n;
    memset(&msg, 0, sizeof(msg));
    msg.mtype = 1;
    int pid = getpid(); // 不同机器的PID_T可能不一样，统一用四个字节来保存
    *((int*)msg.mtext) = pid;
    while (fgets(msg.mtext, MSGMAX, stdin) != nullptr)
    {
        if (msgsnd(msgid, &msg, 4 + strlen(msg.mtext + 4), 0) < 0)
            ERR_EXIT("echo_cli msgsnd");
        memset(msg.mtext + 4, 0,  MSGMAX - 4);
        
        // 接受消息
        if ((n = msgrcv(msgid, &msg, MSGMAX, pid, 0)) < 0)
            ERR_EXIT("echo_cli msgrcv");

        fputs(msg.mtext + 4, stdout);
        memset(msg.mtext + 4, 0, MSGMAX - 4);
    }
}
int main(int argc, char *argv[])
{
    int msgid;
    msgid = msgget(1234, 0); 

    if (msgid == -1)
        ERR_EXIT("msgget");
    
    echo_cli(msgid);
    return 0;
}
