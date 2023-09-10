/*
============================================================================
Name : 3.c
Author : Deep Bansal
Description : Write a program to create a file and print the file descriptor value. 
              Use creat ( ) system call
Date: 18th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;

    fd = creat("sample.txt",S_IRWXU);
    
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }
    
    printf("File created successfully with file descriptor: %d\n", fd);
    
    close(fd);

    return 0;
}
