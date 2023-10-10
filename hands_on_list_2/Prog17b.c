/*
============================================================================
Name : 17a.c
Author : Deep Bansal
Description : Write a program to execute ls -l | wc.
              b. use dup2
Date: 4th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    int pipe_val[2];
    int pid;

    // Child process executes ls -l and sends its output to stdout.
    // Parent process executes wc and takes its input from stdin.

    if (pipe(pipe_val) == -1) {
        perror("Error in creating the pipe");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("Error in executing fork");
        return 1;
    }

    if (pid == 0) {
        // Child process
        close(pipe_val[0]);

        dup2(pipe_val[1], STDOUT_FILENO);
        close(pipe_val[1]); 

        const char* arg1 = "ls";
        const char* arg2 = "-l";
        execlp(arg1, arg1, arg2, NULL);
        perror("Error in execl");
        return 1;

    } else {
        close(pipe_val[1]);

        dup2(pipe_val[0], STDIN_FILENO);
        close(pipe_val[0]);

        execlp("wc", "wc", NULL);
        perror("Error in execl");
        return 1;
    }

    return 0;
}
