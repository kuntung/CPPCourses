#ifndef _IPC_H_
#define _IPC_H_

// 创建信号量集
int sem_create(key_t key)；

// 打开信号量集
int sem_open(key_t key)；

// 设置信号量
int sem_set(int semid, int val)；

// 获取信号量
int sem_get(int semid)；

// 删除一个信号量集
int sem_d(int semid)；

// 信号量P操作封装
int sem_p(int semid)；

// 信号量V操作封装
int sem_v(int semid)；



#endif // _IPC_H_
