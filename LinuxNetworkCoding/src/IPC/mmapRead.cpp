#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define ERR_EXIT(m)\
    do {\
        perror(m);\
        exit(EXIT_FAILURE);\
       } while (0)

typedef struct stu
{
    char name[24];
    int age;
} STU;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage : %s<file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd;
    fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        ERR_EXIT("main open");
    }

    // 进行映射
    STU *p;
    p = (STU*)mmap(NULL, sizeof(STU)*5, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if  (p == NULL)
        ERR_EXIT("main mmap");

    // 通过内存的形式向文件写入内存
    int i;
    for (i = 0; i < 5; ++i)
    {
        printf("name = %s age = %d\n", (p+i)->name, (p+i)->age);
    }

    munmap(p, sizeof(STU)*5); // 接触当前映射
    printf("main exit\n");

    return 0;
}
