#ifndef _SHM_FIFO_H_
#define _SHM_FIFO_H_

#include "ipc.h"

typedef struct shmfifo shmfifo_t;
typedef struct shmhead shmhead_t;

struct shmhead
{
    unsigned int blksize; // 块大小
    unsigned int blocks; // 总快数
    unsigned int rd_index; // 读索引
    unsigned int wr_index; // 写索引
};

struct shmfifo
{
    shmhead_t *p_shm; // 共享内存头部指针
    char *p_payload; // 有效负载的起始地址
   
    int shmid; // 共享内存id
    int sem_mutex; // 用来互斥用的信号量
    int sem_full; // 用来控制内存是否满的信号量
    int sem_empty; // 用来控制内存是否为空的信号量
};

shmfifo_t *shmfifo_init(int key, int blksize, int blocks); // 初始化共享内存
void shmfifo_put(shmfifo_t *fifo, const void *buf); // 生产产品
void shmfifo_get(shmfifo_t *fifo, char *buf); // 消费产品
void shmfifo_destroy(shmfifo_t *fifo); // 销毁缓冲区

#endif // _SHM_FIFO_H_
