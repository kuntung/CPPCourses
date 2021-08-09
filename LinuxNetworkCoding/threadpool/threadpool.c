#include "threadpool.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>

// 线程入口函数
void *thread_routine(void *arg)
{
    struct timespec abstime;
    int timeout;

    printf("thread 0x%x is starting...\n", (int)pthread_self());
    threadpool_t *pool = (threadpool_t *)arg;

    while (1)
    {
        timeout = 0;
        condition_lock(&pool->ready);
        pool->idle++; // 处于等待的状态，idle ++ 
        // 等待队列有任务到来或者线程池销毁通知
        while (pool->first == NULL && !pool->quit)
        {
            printf("thread 0x%x is waiting...\n", (int)pthread_self());
            // condition_wait(&pool->ready); // 实际上，要求能够动态销毁。因此要使用condition_timedwait
            clock_gettime(CLOCK_REALTIME, &abstime);
            abstime.tv_sec += 2; // 超时时间为2s
            int status = condition_timedwait(&pool->ready, &abstime);
            if (status == ETIMEDOUT) // 等待超时通知
            {
                printf("thread 0x%x is wait timed out...\n", (int)pthread_self());
                timeout = 1;
                break; // 跳出while(1)循环，不再等待
            }
        }

        // 等待到条件，处于工作桩体
        --pool->idle;

        if (pool->first != NULL)
        {
            task_t *t = pool->first; // 从对头取出任务来处理
            pool->first = t->next;
            // 执行任务需要一定时间，所以要先解锁，以便生产者进程能够添加新任务。其他消费者线程能够进入等待任务 
            condition_unlock(&pool->ready);
            t->run(t->arg); // 任务执行
            free(t); // 释放空间
            condition_lock(&pool->ready);
        }

        // 如果等待到线程池销毁通知,且任务都执行完毕
        if (pool->quit && pool->first == NULL)
        {
            pool->counter--; // 最后一个工作完成的线程在销毁的时候，会通知线程池
            if (pool->counter == 0)
            {
                condition_signal(&pool->ready);
            }
            condition_unlock(&pool->ready); // 因为break以后，后面的unlock不会执行
            break;
        }
        
        // 超时
        if (timeout && pool->first == NULL)
        {
            pool->counter--; // 工作线程数减一
            condition_unlock(&pool->ready);
            break;
        }

        condition_unlock(&pool->ready);

    }
    printf("thread 0x%x is destroying...\n", (int)pthread_self());
}

void threadpool_init(threadpool_t *pool, int threads)
{
    // 对线程池的各个字段初始化
    condition_init(&pool->ready);
    pool->first = NULL;
    pool->last = NULL;
    pool->counter = 0;
    pool->idle = 0; // 空闲线程数初始化
    pool->max_threads = threads; // 最大线程数
    pool->quit = 0; // 销毁的flag

} // 线程池初始化

void threadpool_add_task(threadpool_t *pool, void *(*run)(void *arg), void *arg)
{
    // 生成新任务
    task_t *newtask = (task_t*)malloc(sizeof(task_t));
    newtask->run = run;
    newtask->arg = arg;
    newtask->next = NULL;

    condition_lock(&pool->ready); // 互斥访问队列
    // 将任务添加到队列中
    if (pool->first == NULL)
    {
        pool->first = newtask;
    }
    else
    {
        pool->last->next = newtask;
    }

    pool->last = newtask;

    // 判断是否有等待的线程
    if (pool->idle > 0)
    {
        condition_signal(&pool->ready);
    }
    else if (pool->counter < pool->max_threads)// 当前无等待线程,并且可以创建新的线程
    {
        pthread_t tid; 
        pthread_create(&tid, NULL, thread_routine, pool);
        ++pool->counter;
    }
    condition_unlock(&pool->ready);

} // 往线程池中添加任务

void threadpool_destroy(threadpool_t *pool)
{
    // 销毁条件：所有线程为idle状态
    if (pool->quit)
    {
        return NULL;
    }
    condition_lock(&pool->ready);
    pool->quit = 1;
    if (pool->counter > 0)
    {
        // 处于工作中的线程无法收到广播
        if (pool->idle > 0)
        {
            condition_broadcast(&pool->ready);
        } // 向idle的线程发送条件广播

        // 线程池等待正在执行任务的线程退出
        while (pool->counter > 0)
        {
            condition_wait(&pool->ready);
        }
    }
    condition_unlock(&pool->ready);
    condition_destroy(&pool->ready);
} // 销毁线程池
