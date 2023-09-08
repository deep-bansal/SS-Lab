/*
============================================================================
Name : 27e.c
Author : Deep Bansal
Description : Write a program to execute ls -Rl by the following system calls
              e. execvp
Date: 4th Sept, 2023.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char* agc[] = {"ls","-Rl",NULL};

    int stats = execvp("ls",agc);

    printf("hello world");
    if(stats == -1){
        perror("Error");
        return 0;
    }

    return 0;
}
