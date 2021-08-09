#include "condition.h"

// 初始化
int condition_init(condition_t *cond)
{
    int status;
    if ((status = pthread_mutex_init(&cond->pmutex, NULL)))
        return status;

    if ((status = pthread_cond_init(&cond->pcond, NULL)))
        return status;

    return 0;
}

// 互斥锁加锁
int condition_lock(condition_t *cond)
{
    return pthread_mutex_lock(&cond->pmutex);
}

int condition_unlock(condition_t *cond)
{
    return pthread_mutex_unlock(&cond->pmutex);
}

// 条件变量等待
int condition_wait(condition_t *cond)
{
    return pthread_cond_wait(&cond->pcond, &cond->pmutex);
}

int condition_timedwait(condition_t *cond, const struct timespec *abstime)
{
    return pthread_cond_timedwait(&cond->pcond, &cond->pmutex, abstime);
}

// 条件变量通知
int condition_signal(condition_t *cond)
{
    return pthread_cond_signal(&cond->pcond);
}

// 通知所有线程
int condition_broadcast(condition_t *cond)
{
    return pthread_cond_broadcast(&cond->pcond);
}
// 条件变量销毁
int condition_destroy(condition_t *cond)
{
    int status;

    if ( status = pthread_mutex_destroy(&cond->pmutex))
        return status;

    if (status = pthread_cond_destroy(&cond->pcond))
        return status;

    return 0;
}
