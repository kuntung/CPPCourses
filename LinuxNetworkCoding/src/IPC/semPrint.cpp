#include <sys/types.h>
#include <sys/wait.h>
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

int semid;

// semP封装
int semP(int semid)
{
    struct sembuf sb = {0, -1, 0};
    int ret;
    ret = semop(semid, &sb, 1); // 1表示只操作一个信号量
    
    if (ret == -1)
        ERR_EXIT("semP semop");

    return ret;
}

//semV封装
int semV(int semid)
{
    struct sembuf sb = {0, 1, 0};
    int ret;
    ret = semop(semid, &sb, 1); // 1表示只操作一个信号量
    
    if (ret == -1)
        ERR_EXIT("semV semop");
    
    return ret;
}

// 打印函数封装
void print(char op_char)
{
    int pause_time;
    srand(getpid());
    int i;
    for (i = 0; i < 10; ++i)
    {
        semP(semid);
        printf("%c", op_char);
        fflush(stdout); // 清空缓冲区
        pause_time = rand() % 3;
        sleep(pause_time);
        printf("%c", op_char);
        fflush(stdout);
        semV(semid);
        pause_time = rand() % 3;
        sleep(pause_time);
    }
}

int main(int argc, char *argv[])
{

    semid = semCreate(IPC_PRIVATE); // 由于是在父子进程间进行操作，因此创建一个私有的IPC对象
    semSetval(semid, 0); 
    pid_t pid;
    pid = fork();
    
    if (pid == -1)
        ERR_EXIT("main fork");
    if (pid > 0)
    {
        semSetval(semid, 1); 
        print('O');
        wait(nullptr);
        semDel(semid);
    }
    else
        print('X');

    return 0;
}
