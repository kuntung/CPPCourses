#include "LinuxNetworkCoding/threadpool/threadpool.h"
#include <stdlib.h>
#include <stdio.h>

void *mytask(void *arg)
{
    printf("thread 0x%0x is working on task %d\n", (int)pthread_self(), *(int*)arg);
    sleep(1);
    free(arg);

    return NULL;
}

int main(int argc, char *argv[])
{
    threadpool_t pool;
    if (argc < 2)
    {
        printf("default threadpool_init...\n");
        threadpool_init(&pool, 3);
    }
    else
    {
        threadpool_init(&pool, atoi(argv[1]));

    }

    int i;
    for (i = 0; i < 10; ++i)
    {
        int *arg = (int *)malloc(sizeof(int));
        *arg = i;
        threadpool_add_task(&pool, mytask, arg);
    }

    // sleep(15);
    threadpool_destroy(&pool);

    return 0;
    

}
