// 条件变量封装
#ifndef _CONDITION_H_
#define _CONDITION_H_

#include <pthread.h>

typedef struct condition
{
    pthread_mutex_t pmutex;
    pthread_cond_t pcond;
} condition_t;

int condition_init(condition_t *cond); // 初始化条件变量
int condition_lock(condition_t *cond); // 锁定一个条件变量，实际上是锁定的mutex
int condition_unlock(condition_t *cond); // 解锁条件变量
int condition_wait(condition_t *cond); // 等待条件变量
int condition_timedwait(condition_t *cond, const struct timespec *abstime); // 超时等待
int condition_signal(condition_t *cond); // 向等待线程通知
int condition_broadcast(condition_t *cond); // 向所有等待线程通知
int condition_destroy(condition_t *cond); // 销毁一个条件变量

#endif // _CONDITION_H_
