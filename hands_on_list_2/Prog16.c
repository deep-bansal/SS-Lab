/*
============================================================================
Name : 16.c
Author : Deep Bansal
Description : Write a program to send and receive data from parent to child vice versa. 
              Use two way communication.
Date: 4th Sept, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    int parent_to_child_fd[2];
    int child_to_parent_fd[2];
    int pid;

    if(pipe(parent_to_child_fd) == -1 || pipe(child_to_parent_fd) == -1){
        perror("error in creating pipe");
        return 0;
    }

    pid = fork();
    if(pid == -1){
        perror("error creating the child");
        return 0;
    }

    if(pid == 0){
        close(child_to_parent_fd[0]);
        char* str = "sending data from child to parent\n";
        int written_text = write(child_to_parent_fd[1],str,strlen(str));
        close(child_to_parent_fd[1]);

        close(parent_to_child_fd[1]);
        char buf[50];
        int charRead = read(parent_to_child_fd[0],buf,sizeof(buf));
        if(charRead == -1){
            perror("error in reading the data");
            return 0;
        }
        buf[charRead] = '\0';
        str = "Child process writing received date from parent: ";
        write(STDOUT_FILENO,str,strlen(str));
        write(STDOUT_FILENO,&buf,charRead);
        close(parent_to_child_fd[0]);
    }
    else{
        close(parent_to_child_fd[0]);
        char* str = "sending data from parent to child\n";
        int written_text = write(parent_to_child_fd[1],str,strlen(str));
        close(parent_to_child_fd[1]);

        close(child_to_parent_fd[1]);
        char buf[50];
        int charRead = read(child_to_parent_fd[0],buf,sizeof(buf));
        if(charRead == -1){
            perror("error in reading the data");
            return 0;
        }
        buf[charRead] = '\0';
        str = "parent process writing received date from child: ";
        write(STDOUT_FILENO,str,strlen(str));
        write(STDOUT_FILENO,&buf,charRead);
        close(child_to_parent_fd[0]);
    }



}