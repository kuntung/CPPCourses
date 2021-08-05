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

int main(void)
{
    int msgid;
    msgid = msgget(1234, 0666 | IPC_CREAT); // 6表示读写权限

    if (msgid == -1)
        ERR_EXIT("msgget");
    
    printf("msgget success\n");
    printf("msgid = %d\n", msgid);
    
    struct msqid_ds buf;
    msgctl(msgid, IPC_STAT, &buf);
    printf("mode = %o\n", buf.msg_perm.mode);
    printf("bytes = %d\n", buf.__msg_cbytes);
    printf("number = %d\n", buf.msg_qnum);
    printf("msgmnb = %d\n", buf.msg_qbytes);
    //msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
