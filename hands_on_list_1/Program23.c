/*
============================================================================
Name : 23.c
Author : Deep Bansal
Description : Write a program to create a Zombie state of the running program.
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
    if(!fork()){
        printf("The PID of child process is %d\n",getpid());
        printf("Exiting child process\n");
        exit(0);

    }else{
        printf("The PID of parent process is %d\n",getpid());
        sleep(60);
    }
    
    return 0;
}
