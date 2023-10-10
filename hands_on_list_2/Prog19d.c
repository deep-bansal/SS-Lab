/*
============================================================================
Name : 19d.c
Author : Deep Bansal
Description : Create a FIFO file by
              d. mknod command
Date: 4th Sept, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int status = mknod("./fifofilemknod",__S_IFIFO | S_IWUSR | S_IRUSR, 0);
    if(status == -1){
        perror("error in creating file");
        return 0;
    }
    return 0;
}

