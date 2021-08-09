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

typedef struct tsd{
    pthread_t tid;
    char *str;
} tsd_t;

pthread_key_t key_tsd;

void *thread_routine(void *arg)
{
    tsd_t *value = (tsd_t*)malloc(sizeof(tsd_t));
    value->tid = pthread_self();
    value->str = (char*)arg;

    pthread_setspecific(key_tsd, value);
    printf("%s setspecific %p\n", (char*)arg, value);

    value = (tsd_t *)pthread_getspecific(key_tsd);
    printf("tid = 0x%x, str = %s\n", value->tid, value->str);

    sleep(2);
    value = (tsd_t *)pthread_getspecific(key_tsd);
    printf("tid = 0x%x, str = %s\n", value->tid, value->str);

    return NULL;
} // 线程入口函数

// 数据销毁函数
void destory_routine(void *value)
{
    printf("destory...\n");
    free(value); // 通过注册的destroy_routine释放在线程入口函数中申请的内存
}

int main(void)
{
    pthread_key_create(&key_tsd, destory_routine); // 所有线程都会有这个特定的key，只是key的value不一样
    
    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1, NULL, thread_routine, (void*)"thread1");
    pthread_create(&tid2, NULL, thread_routine, (void*)"thread2");

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    pthread_key_delete(key_tsd);

    return 0;
}

