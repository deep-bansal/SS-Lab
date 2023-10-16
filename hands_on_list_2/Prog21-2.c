/*
============================================================================
Name : 21.c
Author : Deep Bansal
Description : Write two programs so that both can communicate by FIFO -Use two way communication.
Date: 8th Sept, 2023.
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

    int fdRead = open("fifoFile21-1",O_RDONLY);
    int fdWrite = open("fifoFile21-2",O_WRONLY);
    
    if(fdWrite == -1 || fdRead == -1){
        perror("error in opening in the fifo");
        return 0;
    }

    const char* str = "Writing data into fifo file from 21-2\n";
    int write_status = write(fdWrite,str,strlen(str));
    if(write_status == -1){
        perror("error in writing in the fifo");
        close(fdWrite);
        return 0;
    }
    close(fdWrite);

    char buf[256];

    int read_words = read(fdRead,&buf,sizeof(buf));
    buf[read_words] = '\0';
    write_status = write(STDOUT_FILENO,&buf,read_words);
    
    if(write_status == -1){
        perror("error in writing in the fifo");
        return 0;
    }
    close(fdRead);
}


