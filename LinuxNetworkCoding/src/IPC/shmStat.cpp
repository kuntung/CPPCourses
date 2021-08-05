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
    shmid = shmget(1234, sizeof(STU), IPC_CREAT | 0666); // 读共享内存 

    if (shmid == -1)
    {
        ERR_EXIT("main shmget");
    }

    
    struct shmid_ds buf;
    shmctl(shmid, IPC_STAT, &buf); // 获取共享内存的状态
    printf("shm_segsz: %d\n", buf.shm_segsz);
    printf("shm_atime: %d\n", buf.shm_atime);
    printf("shm_cpid: %d\n", buf.shm_cpid);

    return 0;
}
