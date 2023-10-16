/*
============================================================================
Name : 19e.c
Author : Deep Bansal
Description : Create a FIFO file by
              e. mkfifo library function
Date: 1th Sept, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int status = mkfifo("./mkfifo", S_IWUSR | S_IRUSR);
    if(status == -1){
        perror("error in creating file");
        return 0;
    }
    return 0;
}

