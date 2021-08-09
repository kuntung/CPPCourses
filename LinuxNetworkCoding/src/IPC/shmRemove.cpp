#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define ERR_EXIT(m)\
    do {\
        perror(m);\
        exit(EXIT_FAILURE);\
       } while (0)

typedef struct stu
{
    char name[32];
    int age;
} STU;

int main(int argc, char *argv[])
{
    int shmid;
    shmid = shmget(1234, 0, 0); // 读共享内存 

    if (shmid == -1)
    {
        ERR_EXIT("main shmget");
    }

    STU *p;
    p = (STU*)shmat(shmid, NULL, 0);
    if (p == (void*)-1)
        ERR_EXIT("main shmat");

    printf("name = %s, age = %d\n", p->name, p->age);
    //sleep(10);
    
    while (1)
    {
        if (memcmp(p, "quit", 4) == 0)
            break;
    }
    shmdt(p); // 解除映射
    shmctl(shmid, IPC_RMID, NULL); // 删除共享内存，因为这是随内核持续的
    return 0;
}
