#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <errno.h>

#define ERR_EXIT(m) \
    do{ \
        perror(m); \
        exit(EXIT_FAILURE); \
      } while (0)

typedef struct stu
{
    char name[32];
    int age;
} STU;

int main(void)
{
    int shmid;
    shmid = shm_open("/xyz", O_RDWR, 0);
    if (shmid == -1)
        ERR_EXIT("main shm_open");

    printf("shm open success\n");

    // 获取状态
    struct stat buf;
    if (fstat(shmid, &buf) == -1)
        ERR_EXIT("main fstat");
    
    STU *ps;
    ps = (STU*)mmap(NULL, buf.st_size, PROT_WRITE, MAP_SHARED, shmid, 0);
    
    if (ps == MAP_FAILED)
       ERR_EXIT("main mmap");

    strcpy(ps->name, "xiaotang");
    ps->age = 20;

    close(shmid);

    return 0;
}
