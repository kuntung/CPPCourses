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
    fd = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 0666);
    if (fd == -1)
    {
        ERR_EXIT("main open");
    }

    lseek(fd, sizeof(STU)*5 - 1, SEEK_SET);
    write(fd, "", 1); // 产生40个字节的文件

    // 进行映射
    STU *p;
    p = (STU*)mmap(NULL, sizeof(STU)*5, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if  (p == NULL)
        ERR_EXIT("main mmap");

    // 通过内存的形式向文件写入内存
    char ch = 'a';
    int i;
    for (i = 0; i < 5; ++i)
    {
        memcpy((p+i)->name, &ch, 1); // 对内存的操作也会同步到文件的操作
        (p+i)->age = 20 + i;
        ch++;
    }

    printf("initialize over\n");
    munmap(p, sizeof(STU)*5); // 接触当前映射
    printf("main exit\n");

    return 0;
}
