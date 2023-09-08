/*
============================================================================
Name : 24.c
Author : Deep Bansal
Description : Write a program to create an orphan process.
Date: 4th Sept, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    pid_t p = fork();

    if(p > 0){
        printf("Value of ID as parent process is %d\n",getpid());
        printf("Value of ID of my child process is %d\n",p);

    }
    else{
        printf("The value of my parent process Id is %d\n",getppid());
        sleep(5);
        printf("Value of Id as child process is %d\n",getpid());
        printf("The value of my parent process Id is %d\n",getppid());
    }

}
