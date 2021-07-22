#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

void testWait()
{
   int status = 0;
   wait(&status);
   if (WIFEXITED(status))
   {
        puts("normal termination");
        printf("Child pass num: %d\n", WEXITSTATUS(status));
   }
   else
   {
        puts("non-normal termination");
        printf("Child pass num: %d\n", WEXITSTATUS(status));
        
   }
}

int main(void)
{
    pid_t pid;
    printf("before fork\n");
    pid = fork();
    if (pid == 0)
    {
        printf("entering child process, child pid = %d\n", getpid());
        return getpid();
    }
    else
    {
        printf("fork another child process\n");
        pid = fork();
        if (pid == 0)
        {

            printf("entering another child process, child pid = %d\n", getpid());
            return getpid();
        }
        else
        {
                printf("continue parent process, %d\n", getpid());
                testWait();
        }
    }
    return 0;
}
