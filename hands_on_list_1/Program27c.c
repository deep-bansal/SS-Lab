/*
============================================================================
Name : 27c.c
Author : Deep Bansal
Description : Write a program to execute ls -Rl by the following system calls
              c. execle
Date: 4th Sept, 2023.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    const char* arg1 = "ls";
    const char* arg2 = "-Rl";

    char* env[] = {"PATH=/usr/local/sbin:/usr/local/bin",NULL};

    int stats = execle("/bin/ls",arg1,arg2,NULL,env);

    printf("hello world");
    if(stats == -1){
        perror("Error");
        return 0;
    }

    return 0;
}
