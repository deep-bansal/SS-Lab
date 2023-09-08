/*
============================================================================
Name : 30.c
Author : Deep Bansal
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 4th Sept, 2023.
============================================================================
*/

#include <sys/types.h>
#include <unistd.h> 
#include<sys/stat.h>
#include<stdio.h>

void main() {
    pid_t child;
    child = fork();

    if(!child) { 
        setsid();
        chdir("/");
        umask(0);
        while(1) { 
            sleep(2);
            printf("PID: %d\n", getpid());
            printf("Daemon process is running...\n");
        }
    } else {
        _exit(0);
    }
}