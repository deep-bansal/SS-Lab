/*
============================================================================
Name : 21.c
Author : Deep Bansal
Description :   Write a program, call fork and print the parent and child process id.
Date: 4th Sept, 2023.
============================================================================
*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    if(!fork()){
        printf("Child process id is %d\n",getpid());
        exit(0);

    }
    else{
        printf("Parent process id is %d\n",getpid());

    }   
    return 0;
}


       
