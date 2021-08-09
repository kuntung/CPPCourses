#include "LinuxNetworkCoding/shmfifo/shmfifo.h"

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#define ERR_EXIT(m) \
        do \
        { \
             perror(m); \
             exit(EXIT_FAILURE);    \
        } while (0);


struct student
{
    char name[32];
    int age;
};

int main(void)
{
    shmfifo_t* shmfifo1 = shmfifo_init(1234, sizeof(student), 3);
    shmfifo_destroy(shmfifo1);
    return 0;
}