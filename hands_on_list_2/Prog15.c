/*
============================================================================
Name : 15.c
Author : Deep Bansal
Description : Write a simple program to send some data from parent to the child 
              process.
Date: 1th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    int pipe_val[2];
    int pid;

    if(pipe(pipe_val) == -1){
        perror("Error in creating the pipe");
        return 0;
    }

    pid = fork();
    if(pid == -1){
        perror("error creating the child");
        return 0;
    }
    
    if(pid == 0){
        close(pipe_val[1]);
        char buf[50];
        int charRead = read(pipe_val[0],buf,sizeof(buf));
        if(charRead == -1){
            perror("error in reading the data");
            return 0;
        }
        buf[charRead] = '\0';
        char* str = "Child process writing\n";
        write(STDOUT_FILENO,str,strlen(str));
        write(STDOUT_FILENO,&buf,charRead);
        close(pipe_val[0]);
        
    }
    else{
        close(pipe_val[0]);
        char* str = "Hello I am sending the data to read\n";
        int charWritten = write(pipe_val[1],str,strlen(str));
        if(charWritten == -1){
            perror("error writing the data");
            return 0;
        }
        printf("Done from parent side\n");
        close(pipe_val[1]);

    }



}


