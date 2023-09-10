/*
============================================================================
Name : 1a.c
Author : Deep Bansal
Description : Create the following types of a files using (ii) system call 
              c. FIFO (mkfifo Library Function or mknod system call)
Date: 18th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdlib.h>

int main(){
    int fifo_file = mknod("fifoFile", S_IFIFO,0);
    if(fifo_file == -1){
        perror("error in creating fifo link\n");
        return 0;
    }

}