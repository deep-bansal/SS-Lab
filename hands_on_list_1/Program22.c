/*
============================================================================
Name : 22.c
Author : Deep Bansal
Description : Write a program, open a file, call fork, and 
              then write to the file by both the child as well as the parent processes.
              Check output of the file.
Date: 4th Sept, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    int fd = open("prog22.txt",O_RDWR);
    if(fd == -1){
        perror("Error in opening the file\n");
        return 0;
    }

    if(!fork()){
        char* str = "This line is written by chlid process in the file\n";
        write(fd,str,strlen(str));
        close(fd);
        exit(0);
    }
    else{
        char* str = "This line is written by parent process in the file\n";
        wait(NULL);
        write(fd,str,strlen(str));
    }

    close(fd);

    
    return 0;
}


       
