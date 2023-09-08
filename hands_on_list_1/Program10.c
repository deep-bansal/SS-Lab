/*
============================================================================
Name : 10.c
Author : Deep Bansal
Description : Write a program to open a file with read write mode, write 10 bytes, 
              move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
              a. check the return value of lseek
              b. open the file with od and check the empty spaces in between the data.
Date: 25th Aug, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd = open("sample.txt",O_RDWR);
    if(fd == -1){
        perror("File opening error");
        return 0;
    }

    char buf[10];
    for(int i = 0; i < 10; i++){
        read(STDIN_FILENO,&buf[i],1);
    }

    int content_write = write(fd,&buf,sizeof(buf));
    if(content_write == -1){
        printf("Error in writing the data");
        return 0;
    }
    int seek = lseek(fd,10,SEEK_SET);
    // printf("%d",seek);
    for(int i = 0; i < 10; i++){
        read(STDIN_FILENO,&buf[i],1);
    }

    content_write = write(fd,&buf,sizeof(buf));
    if(content_write == -1){
        printf("Error in writing the data");
        return 0;
    }

    close(fd);    
    return 0;
}
