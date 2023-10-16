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
    fd_set rf;
    int fd = open("fifoFile22",O_RDONLY);

    if(fd == -1){
        perror("error in opening in the fifo");
        return 0;
    }

    FD_ZERO(&rf);
    FD_SET(fd,&rf);

    struct timeval timep;
    timep.tv_sec = 10;
    timep.tv_usec = 0;


    int rval = select(fd+1, &rf, NULL,NULL, &timep);

    if (rval == -1){
        perror("error");
        return 0;
    }
    else if (rval){
        char buf[256];
        int read_words = read(fd,&buf,sizeof(buf));
         if (read_words == -1) {
            perror("error in reading from the fifo");
            close(fd);
            return 1;
        }
        buf[read_words] = '\0';
        int write_status = write(STDOUT_FILENO,&buf,read_words);
        
        if(write_status == -1){
            perror("error in writing in the fifo");
            return 0;
        }
    }
    else{
        const char* x = "No data.\n";
        write(STDOUT_FILENO,x,strlen(x));
    }
    close(fd);
}
