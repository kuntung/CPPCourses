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

#define MSGMAX 65536
int main(int argc, char *argv[])
{
    int flag = 0;
    int type = 0;
    int opt;
    while (1)
    { opt = getopt(argc, argv, "nt:");
        if (opt == '?')
            ERR_EXIT("main getopt");
        if (opt == -1)
            break;
        switch (opt)
        {
            case 'n':
                flag |= IPC_NOWAIT; 
                break;
            case 't':
                type = atoi(optarg);
                break;
        }
    }
    int msgid;
    msgid = msgget(1234, 0); 

    if (msgid == -1)
        ERR_EXIT("msgget");
    
    struct msgbuf *ptr;
    ptr =(struct msgbuf*)malloc(sizeof(long) + MSGMAX);
    ptr->mtype = type;
    int n = 0;
    if ((n = msgrcv(msgid, ptr, MSGMAX,type, flag)) < 0) // 非阻塞模式
        ERR_EXIT("main msgrcv");
    
    printf("read %d bytes type = %ld\n", n, ptr->mtype);
    return 0;
}
