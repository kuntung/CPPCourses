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

#define DELAY ((rand()%5 + 1))

union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

int semid;
// semP封装
int semP(int no)
{
    struct sembuf sb = {no, -1, 0};
    int ret;
    ret = semop(semid, &sb, 1); // 1表示只操作一个信号量
    
    if (ret == -1)
        ERR_EXIT("semP semop");

    return ret;
}

//semV封装
int semV(int no)
{
    struct sembuf sb = {no, 1, 0};
    int ret;
    ret = semop(semid, &sb, 1); // 1表示只操作一个信号量
    
    if (ret == -1)
        ERR_EXIT("semV semop");
    
    return ret;
}

// wait_for_2fork
void wait_for_2fork(int no)
{
   int left = no;
   int right = (no + 1) % 5;

   struct sembuf buf[2] = {
                {left, -1, 0}, 
                {right, -1, 0}
                }; // 当前两个信号量的编号为哲学家左右手刀叉编号，P操作
   semop(semid, buf, 2); // 同时操作两个信号量P，不会出现死锁

}

// free_2fork
void free_2fork(int no)
{
   int left = no;
   int right = (no + 1) % 5;

   struct sembuf buf[2] = {
                {left, 1, 0}, 
                {right, 1, 0}
                }; // 当前两个信号量的编号为哲学家左右手刀叉编号，P操作
    semop(semid, buf, 2); // 释放两把刀叉
}

// 哲学家行为函数
void philosophere(int no)
{
    for (;;)
    {
        int left = no;
        int right = (no + 1) % 5;
        printf("philosophere<%d> is thinking...\n", no);
        sleep(DELAY);
        printf("philosophere<%d> is hungry...\n", no);
        semP(left);
        sleep(DELAY);
        semP(right); // 分开获取两把刀叉
        printf("philosophere<%d> is eating...\n", no);
        sleep(DELAY);
        semV(left);
        sleep(DELAY);
        semV(right);
        
    }
}
int main(int argc, char *argv[])
{

    semid = semget(IPC_PRIVATE, 5, IPC_CREAT | 0666); // 5表示五把刀叉资源

    if (semid == -1)
        ERR_EXIT("main semget");

    union semun su;
    su.val = 1; // 表示刀叉处于可用状况
    int i;
    for (i = 0; i < 5; ++i)
    {
        semctl(semid, i, SETVAL, su); 
    }

    int no;
    pid_t pid;
    for (i = 0; i < 5; ++i)
    {
        pid = fork();
        if (pid == -1)
            ERR_EXIT("main fork");

        if (pid == 0)
        {
            no = i;
            break;
        }
    }

    philosophere(no);

    return 0;
}
