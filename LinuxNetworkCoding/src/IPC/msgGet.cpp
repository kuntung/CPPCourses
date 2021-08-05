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
    msgid = msgget(1234, 0666 | IPC_CREAT | IPC_EXCL); // 6表示读写权限

    if (msgid == -1)
        ERR_EXIT("msgget");
    
    printf("msgget success\n");
    return 0;
}
