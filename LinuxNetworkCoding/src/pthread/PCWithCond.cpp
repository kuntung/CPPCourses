#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE); \
       } while (0)

#define CONSUMER_COUNT 2
#define PRODUCERS_COUNT 1

pthread_cond_t g_cond;
pthread_mutex_t g_mutex;

pthread_t g_thread[CONSUMER_COUNT + PRODUCERS_COUNT];

int nready = 0;

// 消费者入口函数
void *consume(void *arg)
{
    int num = *((int*)arg); 
    while (1){
        pthread_mutex_lock(&g_mutex);
        while (nready == 0)
        {
            printf("customer<%d> begin wait a condition...\n", (int)pthread_self());
            pthread_cond_wait(&g_cond, &g_mutex); // 当等待条件的时候，对互斥锁解锁
        }

        printf("customer<%d> end wait a condition...\n", (int)pthread_self());
        printf("customer<%d> begin consume product...\n", (int)pthread_self());
        --nready;
        printf("customer<%d> end consume product...\n", (int)pthread_self());
        pthread_mutex_unlock(&g_mutex);
        sleep(1);
    }
    return NULL;
}

// 生产者入口函数
void *produce(void *arg)
{
    int num = *((int*)arg); 
    while (1) // 生产代码
    {
        pthread_mutex_lock(&g_mutex);
        printf("producer<%d> begin produce product...\n", (int)pthread_self());
        ++nready;
        printf("producer<%d> end procduce product...\n", (int)pthread_self());
        if (nready > 0)
                pthread_cond_signal(&g_cond); // 发起通知
        printf("producer<%d> signal...\n",(int)pthread_self());
        pthread_mutex_unlock(&g_mutex);
        sleep(5);
    }
    return NULL;
}

int main(void)
{
    int i;
    
    pthread_cond_init(&g_cond, NULL); // 默认初始化
    pthread_mutex_init(&g_mutex, NULL); // 采用默认属性NULL

    // 创建若干个线程
    for (i = 0; i < CONSUMER_COUNT; ++i)
    {
        pthread_create(&g_thread[i], NULL, consume, (void*)&i);
    }

    for (i = 0; i < PRODUCERS_COUNT; ++i)
    {
        pthread_create(&g_thread[i + CONSUMER_COUNT], NULL, produce, (void*)&i);
    }

    for (i = 0; i < CONSUMER_COUNT + PRODUCERS_COUNT; ++i)
    {
        pthread_join(g_thread[i], NULL); // 等待每个线程终止
    }

    pthread_mutex_destroy(&g_mutex);
    pthread_cond_destroy(&g_cond);

    return 0;
}

