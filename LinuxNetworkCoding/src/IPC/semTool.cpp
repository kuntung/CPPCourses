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
    printf("curent val is %d\n", ret);
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

// 信号量P操作封装
int semP(int semid)
{
    struct sembuf sb = {0, -1, 0}; // 对信号量集中第一个信号，进行-1（P操作）
    int ret;
    ret = semop(semid, &sb, 1); // 1表示只操作一个信号量
    
    if (ret == -1)
        ERR_EXIT("semP semop");
    return ret;
}

// 信号量V操作封装
int semV(int semid)
{
    struct sembuf sb = {0, 1, 0}; // 对信号量集中第一个信号，进行1（V操作）
    int ret;
    ret = semop(semid, &sb, 1); // 1表示只操作一个信号量
    
    if (ret == -1)
        ERR_EXIT("semV semop");


}

// 获取权限
int semGetmode(int semid)
{
    union semun su;
    struct semid_ds sem;

    su.buf = &sem;
    int ret = semctl(semid, 0, IPC_STAT, su);
    if (ret == -1)
        ERR_EXIT("semGetmode semctl");

    printf("current permissions: %o\n", su.buf->sem_perm.mode);

    return ret;
}

// 设置权限
int semSetmode(int semid, char *mode)
{
    union semun su;
    struct semid_ds sem;
    su.buf = &sem;
    int ret = semctl(semid, 0, IPC_STAT, su);
    if (ret == -1)
        ERR_EXIT("semctl");

    printf("current permissions is %o\n", su.buf->sem_perm.mode);
    sscanf(mode, "%o", (unsigned int*)&su.buf->sem_perm.mode);
    
    ret = semctl(semid, 0, IPC_SET, su); // 设置权限
    if (ret == -1)
        ERR_EXIT("semSetmode semctl");

    printf("permissions updated...\n");

    return ret;
}

// 提示信息
void usage(void)
{
    fprintf(stderr, "usage:\n");
    fprintf(stderr, "semtool -c\n");
    fprintf(stderr, "semtool -d\n");
    fprintf(stderr, "semtool -p\n");
    fprintf(stderr, "semtool -v\n");
    fprintf(stderr, "semtool -s <val>\n");
    fprintf(stderr, "semtool -g\n");
    fprintf(stderr, "semtool -f\n");
    fprintf(stderr, "semtool -m <mode>\n");
}
int main(int argc, char *argv[])
{
    int opt;

    opt = getopt(argc, argv, "cdpvs:gfm:");
    if (opt == '?')
        exit(EXIT_FAILURE);

    if (opt == -1)
    {
        usage();
        exit(EXIT_FAILURE);
    }

    key_t key = ftok(".", 's'); // 产生一个随机的key
    int semid;

    switch (opt)
    {
        case 'c':
            semid = semCreate(key);
            break;
        case 'p':
            semid = semOpen(key);
            semP(semid);
            semGetval(semid);
            break;
        case 'v':
            semid = semOpen(key);
            semV(semid);
            semGetval(semid);
            break;
        case 'd':
            semid = semOpen(key);
            semDel(semid);
            break;
        case 's':
            semid = semOpen(key);
            semSetval(semid, atoi(optarg));
            break;
        case 'g':
            semid = semOpen(key);
            semGetval(semid);
            break;
        case 'f':
            semid = semOpen(key);
            semGetmode(semid);
            break;
        case 'm':
            semid = semOpen(key);
            semSetmode(semid, argv[2]);
            break;
        case 'h':
            usage();
            break;
        default:
            usage();
            break;
    }
    return 0;
}
