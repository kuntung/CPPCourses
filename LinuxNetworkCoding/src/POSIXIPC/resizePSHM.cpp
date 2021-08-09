#include <unistd.h>
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
    shmid = shm_open("/xyz", O_CREAT | O_RDWR, 0666);
    if (shmid == -1)
        ERR_EXIT("main shm_open");

    printf("shm open success\n");

    if (ftruncate(shmid, sizeof(STU)) == -1)
        ERR_EXIT("main ftruncate");
    close(shmid);

    return 0;
}
