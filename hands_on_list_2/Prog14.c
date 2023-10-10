/*
============================================================================
Name : 14.c
Author : Deep Bansal
Description : Write a simple program to create a pipe, write to the pipe, 
              read from pipe and display on the monitor.
Date: 4th Sept, 2023.
============================================================================
*/
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
    int fd[2];
    int pipe_val = pipe(fd);
    if(pipe_val == -1){
        perror("error in creating the pipe");
        return 0;
    }

   
    const char* line;
    if(!fork()){
        line = "This text is written by pipe's write end by child process\n";
        write(fd[1],line,strlen(line));
        close(fd[1]);
    }
    else{

        wait(NULL);
        close(fd[1]);
        char buf;
        int charRead;
        
        while((charRead = read(fd[0],&buf,1)) > 0){
            write(STDOUT_FILENO,&buf,1);
        }

        close(fd[0]);
    }

    return 0;
}