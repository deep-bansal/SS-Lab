/*
============================================================================
Name : 4.c
Author : Deep Bansal
Description : Write a program to open an existing file with read write mode. 
              Try O_EXCL flag also.
Date: 18th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int fd;

    fd = open("sample.txt", O_RDWR | O_EXCL); //creates a file if not exist

    if (fd == -1) {
        perror("error in creating the file");
        return 0;
    } else {
        printf("File opened successfully in read-write mode.\n");
    }

    // Close the file
    close(fd);

    return 0;
}
