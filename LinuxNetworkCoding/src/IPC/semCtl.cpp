#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/sem.h>
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

union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};
// 创建信号量集
int semCreate(key_t key)
{
    int semid;
    semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
    if (semid == -1)
        ERR_EXIT("semCreate semget");

    return semid;
}

// 打开信号量集
int semOpen(key_t key)
{
    int semid;
    semid = semget(key, 0, 0);
    if (semid == -1)
        ERR_EXIT("semOpen semget");

    return semid;
}

// 设置信号量
int semSetval(int semid, int val)
{
    union semun su;
    su.val = val;
    int ret;
    ret = semctl(semid, 0, SETVAL, su);

    if (ret == -1)
        ERR_EXIT("semSetval semctl");

    return 0;
}

// 获取信号量
int semGetval(int semid)
{
    int ret;
    ret = semctl(semid, 0, GETVAL, 0);
    if (ret == -1)
        ERR_EXIT("semGetval semctl");

    return ret;
}

// 删除一个信号量集
int semDel(int semid)
{
    int ret;
    ret = semctl(semid, 0, IPC_RMID, 0);
    if (ret == -1)
        ERR_EXIT("semDel semctl");

    return ret;
}
int main(int argc, char *argv[])
{
    int semid;

    semid = semCreate(1234);
    sleep(5);

    semDel(semid);
    return 0;
}
