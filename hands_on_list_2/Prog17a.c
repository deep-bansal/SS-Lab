/*
============================================================================
Name : 17a.c
Author : Deep Bansal
Description : Write a program to execute ls -l | wc.
              a. use dup
Date: 4th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int pipe_val[2];
    int pid;
    // child process executes ls -l and send it to stdout and parent execute wc taking stdin 

    pid = fork();
    if(pid == -1){
        perror("Error in executing fork");
        return 1;
    }
    if(pipe(pipe_val) == -1){
        perror("error in creating the pipe");
        return 0;
    }

    if(pid == 0){
        close(pipe_val[0]);
        pipe_val[1] = dup(STDOUT_FILENO);

        const char* arg1 = "ls";
        const char* arg2 = "-l";

        int stats = execl("/bin/ls",arg1,arg2,NULL);
        close(pipe_val[1]);
        close(STDOUT_FILENO);
    }
    else{
        close(pipe_val[1]);
        close(STDOUT_FILENO);
        pipe_val[0] = dup(STDERR_FILENO);
        // close(pipe_val[0]);

        execlp("wc", "wc", NULL);

        

    }


    return 0;
}

