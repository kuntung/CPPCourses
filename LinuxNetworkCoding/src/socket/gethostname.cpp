#include <iostream>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define ERR_EXIT(m) \
        do  \
        {   \
            perror(m);  \
            exit(EXIT_FAILURE); \
        } while(0);
// getlocalip函数封装
int getlocalip(char *ip)
{
    char host[100] = {0};
    if (gethostname(host, sizeof host) < 0)
        return -1;
    struct hostent *hp;
    if ((hp = gethostbyname(host)) == nullptr)
        return -1;
    strcpy(ip, inet_ntoa(*(struct in_addr*)hp->h_addr));

    return 0;
}
int main(void)
{
    char host[100];
    if (gethostname(host, sizeof(host)) < 0)
        ERR_EXIT("gethostname");

    struct hostent *hp;
    if (( hp = gethostbyname(host)) == nullptr)
        ERR_EXIT("gethostbyname");

    int i;
    while (hp->h_addr_list[i] != nullptr)
    {
        printf("hostname: %s\n", inet_ntoa(*(struct in_addr*)hp->h_addr_list[i]));
        ++i;
    }
    
    char ip[16] = {0};
    getlocalip(ip);
    printf("local = %s\n", ip);
    return 0;
}
