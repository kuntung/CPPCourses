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

#define CONSUMER_COUNT 3
#define PRODUCERS_COUNT 5
#define BUFSIZE 10

int g_buffer[BUFSIZE]; // 环形缓冲区

unsigned short in = 0;
unsigned short out = 0;
unsigned short produce_id = 0;
unsigned short consume_id = 0;

sem_t g_sem_full;
sem_t g_sem_empty;
pthread_mutex_t g_mutex;

pthread_t g_thread[CONSUMER_COUNT + PRODUCERS_COUNT];

// 消费者入口函数
void *consume(void *arg)
{
    int num = *((int*)arg); 
    while (1){
    printf("thread<%d>: wait buffer empty\n", pthread_self());
    sem_wait(&g_sem_empty);

    pthread_mutex_lock(&g_mutex);
        for (int i = 0; i < BUFSIZE; ++i)
        {
            printf("%02d", i);
            if (g_buffer[i] == -1)
                printf("%s", "null");
            else
                printf("%d", g_buffer[i]);

            if (i == out)
                printf("\t<--consume");
            
            printf("\n");
        }
    
    consume_id = g_buffer[out];

        printf("thread<%d>: begin consum product %d \n",pthread_self(), consume_id);
        g_buffer[out] = -1;
       
        out = (out + 1) % BUFSIZE; // 唤醒缓冲区
        printf("thread<%d>: end consume product %d \n",pthread_self(), consume_id++);
    pthread_mutex_unlock(&g_mutex);
    sem_post(&g_sem_full);
    sleep(5);
    }

    return NULL;
}

// 生产者入口函数
void *produce(void *arg)
{
    int num = *((int*)arg); 
    while (1) // 生产代码
    {
        printf("thread<%d>: wait buffer full \n", pthread_self);
        sem_wait(&g_sem_full); 
        pthread_mutex_lock(&g_mutex);
        for (int i = 0; i < BUFSIZE; ++i)
        {
            printf("%02d", i);
            if (g_buffer[i] == -1)
                printf("%s", "null");
            else
                printf("%d", g_buffer[i]);

            if (i == in)
                printf("\t<--produce");
            
            printf("\n");
        }
        printf("thread<%d>: begin produce product %d \n",  pthread_self, produce_id);
        g_buffer[in] = produce_id;
       
        in = (in + 1) % BUFSIZE; // 唤醒缓冲区
        printf("thread<%d>: end produce product %d \n",pthread_self(), produce_id++);

        pthread_mutex_unlock(&g_mutex);
        sem_post(&g_sem_empty);
        sleep(5);
    }

    return NULL;
}

int main(void)
{
    int i;
    for (i = 0; i < BUFSIZE; ++i)
    {
        g_buffer[i] = -1; // 初始化仓库状态
    }

    sem_init(&g_sem_full, 0, BUFSIZE); // 初始一个匿名信号量g_sem_full，并且计数值为缓冲区大小
    sem_init(&g_sem_empty, 0, 0);

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

    sem_destroy(&g_sem_full);
    sem_destroy(&g_sem_empty);
    pthread_mutex_destroy(&g_mutex);

    return 0;
}

