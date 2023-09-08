/*
============================================================================
Name : 14.c
Author : Deep Bansal
Description : Write a program to find the type of a file.
              a. Input should be taken from command line.
              b. program should be able to identify any type of a file.

Date: 25th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>



int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    struct stat file_info;

    if (stat(filename, &file_info) == -1) {
        perror("Error while getting file information");
        return 1;
    }

    printf("%d\n",file_info.st_mode);

    if (S_ISREG(file_info.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(file_info.st_mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(file_info.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISFIFO(file_info.st_mode)) {
        printf("FIFO/Named pipe\n");
    } else if (S_ISSOCK(file_info.st_mode)) {
        printf("Socket\n");
    } else if (S_ISCHR(file_info.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(file_info.st_mode)) {
        printf("Block device\n");
    } else {
        printf("Unknown file type\n");
    }

    return 0;
}