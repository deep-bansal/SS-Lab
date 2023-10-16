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
    int status = mkfifo("./fifoFile20", 0777);
    if(status == -1){
        perror("error in creating file");
        return 0;
    }

    int fd = open("fifoFile20",O_WRONLY);
    
    if(fd == -1){
        perror("error in opening in the fifo");
        return 0;
    }

    const char* str = "Writing data into fifo file";
    int write_status = write(fd,str,strlen(str));
    if(write_status == -1){
        perror("error in writing in the fifo");
        close(fd);
        return 0;
    }
    close(fd);
}


