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
    shmid = shm_open("/xyz", O_RDONLY, 0);
    if (shmid == -1)
        ERR_EXIT("main shm_open");

    printf("shm open success\n");

    // θ·εηΆζ
    struct stat buf;
    if (fstat(shmid, &buf) == -1)
        ERR_EXIT("main fstat");
    
    STU *ps;
    ps = (STU*)mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, shmid, 0);
    
    if (ps == MAP_FAILED)
       ERR_EXIT("main mmap");

    printf("name = %s, age = %d\n", ps->name, ps->age);
    close(shmid);

    return 0;
}
