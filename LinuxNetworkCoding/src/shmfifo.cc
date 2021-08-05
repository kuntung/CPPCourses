#include "ipc.h"
#include "shmfifo.h"
#include <assert.h>

shmfifo_t *shmfifo_init(int key, int blksize, int blocks)
{
    shmfifo_t *fifo = (shmfifo_t*)malloc(sizeof(shmfifo_t));
    
    assert(fifo != NULL);

    memset(fifo, 0, sizeof(shmfifo_t));

    int shmid;
    shmid = shmget(shmid, 0, 0); // 尝试打开这块共享内存

    // 创建共享缓冲区
    int size = sizeof(shmhead_t) + blksize * blocks;
    if (shmid == -1)
    {
        fifo->shmid = shmget(key, size, IPC_CREAT | 0666);
        if (fifo->shmid == -1)
            ERR_EXIT("[shmfifo_init]shmget");

        fifo->p_shm = shmat(fifo->shmid, NULL, 0); // 将fifo同共享内存shmid绑定连接

        if (fifo->p_shm == (shmhead_t*)-1)
            ERR_EXIT("[shmfifo_init]shmat");

        fifo->p_payload = (char*)(fifo->p_shm + 1);

        // 创建信号量
        fifo->sem_mutex = sem_create(key); // 信号量的key可以和共享内存的key一样。但是两个共享内存和两个信号量的key不能一样
        fifo->sem_full = sem_create(key + 1);
        fifo->sem_empty = sem_create(key + 2);

        // 信号量值初始化
        sem_setval(fifo->sem_mutex, 1); // 信号量充当互斥锁
        sem_setval(fifo->sem_full, blocks); // 缓冲区容量大小
        sem_setval(fifo->sem_empty, 0); // 缓冲区的产品数
    }
    else // shmid已经存在
    {
        fifo->shmid = shmid;
        fifo->p_shm = (shmhead_t*)shmat(fifo->shmid, NULL, 0);
        if (fifo->p_shm == (shmhead_t*)-1)
            ERR_EXIT("[shmfifo_init]shmat");
        
        fifo->p_payload = (char*)(fifo->p_shm + 1);
        fifo->sem_mutex = sem_open(key);
        fifo->sem_full = sem_open(key + 1);
        fifo->sem_empty = sem_open(key + 2);
    }

    return NULL;
}

// 缓冲区put
void shmfifo_put(shmfifo_t *fifo, const void *buf)
{
   sem_p(fifo->sem_full);
   sem_p(fifo->sem_mutex);
   memcpy(fifo->p_shm->p_payload + fifo->p_shm->blksize*fifo->p_shm->wr_index, buf, fifo->p_shm->blksize); // 通过memcpy将消息放到缓冲区
   fifo->p_shm->wr_index = (fifo->p_shm->wr_index + 1) % fifo->blocks; // 环形缓冲区下一个产品的放置位置
   sem_p(fifo->sem_mutex);
   sem_v(fifo->sem_empty);
}

void shmfifo_get(shmfifo_t *fifo, char *buf)
{
   sem_p(fifo->sem_empty);
   sem_p(fifo->sem_mutex);
   memcpy(buf, fifo->p_shm->p_payload + fifo->p_shm->blksize*fifo->p_shm->rd_index, fifo->p_shm->blksize); // 通过memcpy将消息缓冲区数据取走
   fifo->p_shm->rd_index = (fifo->p_shm->rd_index + 1) % fifo->p_shm->blocks; // 指向环形缓冲区下一个产品的放置位置
   sem_p(fifo->sem_mutex);
   sem_v(fifo->sem_full);
    
}

// 共享内存的释放
void shmfifo_destroy(shmfifo_t *fifo)
{
    sem_d(fifo->sem_mutex);
    sem_d(fifo->sem_full);
    sem_d(fifo->sem_empty); // 变量删除
   
    int shmid = fifo->shmid; // 保存共享内存的id
    shmdt(fifo->p_shm); // 

    shmctl(fifo->shmid, IPC_RMID, 0);
    free(fifo);
}
