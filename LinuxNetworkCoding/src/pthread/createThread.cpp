#include <pthread.h>
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


void *thread_routine(void *arg)
{
    for (int i = 0; i < 20; ++i)
    {
        printf("B");
        fflush(stdout);
        usleep(20);
        if (i == 3){
            char *ret = "ABC";
            pthread_exit((void*)ret);
        }
    }

    sleep(3);
    return NULL;
} // 线程入口函数

int main(void)
{
    pthread_t tid;

    int ret;
    ret = pthread_create(&tid, NULL, thread_routine, NULL); 
    // 参数分别为：线程ID,线程属性，线程入口函数，线程传入参数
    if (ret != 0)
    {
        // 主要ret != 0就是失败了
        fprintf(stderr, "pthread_create:%s\n", strerror(ret));
        exit(EXIT_FAILURE); // 这里不自定义ERR_EXIT是因为该宏检查的是全局的errno变量
    }

    for (int i = 0; i < 20; ++i)
    {
        printf("A");
        fflush(stdout);
        usleep(20);
    }

    void *value;
    if ((ret = pthread_join(tid, &value)) != 0)
    {
        fprintf(stderr, "pthread_join:%s\n", strerror(ret));
        exit(EXIT_FAILURE); // 这里不自定义ERR_EXIT是因为该宏检查的是全局的errno变量

    }

    printf("\n");
    printf("return msg: %s\n", (char*)(value));
    return 0;
}

