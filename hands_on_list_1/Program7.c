/*
============================================================================
Name : 7.c
Author : Deep Bansal
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 25th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    if(argc != 3) {
        perror("invalid arguments");
        return 0;
    }

    int fd_read = open(argv[1],O_RDONLY);
    int fd_write = open(argv[2],O_RDWR | O_EXCL);

    if(fd_read == -1 || fd_write == -1){
        perror("error opening file");
        return 0;
    }

    while(1){
        char buf;
        int char_read = read(fd_read,&buf,1);
        if(char_read == 0)
            break;
        int char_written = write(fd_write,&buf,1);
    }
    int fd_read_close = close(fd_read);
    int fd_write_close = close(fd_write);

    if(fd_read_close == -1 || fd_write_close == -1){
        perror("error closing file");
        return 0;
    }

    return 0;
}
