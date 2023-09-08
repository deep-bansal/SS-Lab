/*
============================================================================
Name : 12.c
Author : Deep Bansal
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 25th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int fd_read = open(argv[1],O_WRONLY);
    if(fd_read == -1){
        perror("Error in opening the file");
        return 0;
    }
    int stats =  fcntl(fd_read, F_GETFL,0);

    int fflags = stats & O_ACCMODE;
    if(fflags == O_RDONLY){
        const char* x = "opened in read only mode\n";
        write(STDOUT_FILENO,x,strlen(x));

    }
    else if (fflags == O_WRONLY)
    {
        const char* x = "opened in write only mode\n";
        write(STDOUT_FILENO,x,strlen(x));

    }
    else if (fflags = O_RDWR){
          const char* x = "opened in read and write mode\n";
          write(STDOUT_FILENO,x,strlen(x));
    }

    int fd_read_close = close(fd_read);
       if(fd_read_close == -1){
        perror("totally useless");
    }

    return 0;
}


