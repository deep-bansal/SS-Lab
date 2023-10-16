/*
============================================================================
Name : 20.c
Author : Deep Bansal
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 1th Sept, 2023.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>           
#include <sys/stat.h>         
#include <stdio.h>
#include <string.h>

int main(){

    int fd = open("fifoFile20",O_RDONLY);
    
    if(fd == -1){
        perror("error in opening in the fifo");
        return 0;
    }

    char buf[256];

    int read_words = read(fd,&buf,sizeof(buf));
    buf[read_words] = '\0';
    int write_status = write(STDOUT_FILENO,&buf,read_words);
    
    if(write_status == -1){
        perror("error in writing in the fifo");
        return 0;
    }
    close(fd);
}


