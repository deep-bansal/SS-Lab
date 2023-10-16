/*
============================================================================
Name : 22.c
Author : Deep Bansal
Description : Write a program to wait for data to be written into FIFO within 
              10 seconds, use select system call with FIFO.
Date: 8th Sept, 2023.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>             
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int main(){
    int fd = open("fifoFile22",O_WRONLY);
    
    if(fd == -1){
        perror("error in opening in the fifo");
        return 0;
    }

    sleep(13);

    const char* str = "Writing data into fifo file from 22-1\n";
    int write_status = write(fd,str,strlen(str));
    if(write_status == -1){
        perror("error in writing in the fifo");
        close(fd);
        return 0;
    }
    close(fd);
}


