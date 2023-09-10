/*
============================================================================
Name : 13.c
Author : Deep Bansal
Description : Write a program to wait for a STDIN for 10 seconds using select. 
              Write a proper print statement to verify whether the data is available 
              within 10 seconds or not (check in $man 2 select).

Date: 25th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    fd_set rf;

    FD_ZERO(&rf);
    FD_SET(0,&rf);


    struct timeval timep;
    timep.tv_sec = 10;
    timep.tv_usec = 0;


    int rval = select(1, &rf, NULL,NULL, &timep);

    if (rval == -1)
        perror("error");
    else if (rval){
        const char* x = "Data is present.\n";
        write(STDOUT_FILENO,x,strlen(x));

    }
    else{
        const char* x = "No data.\n";
        write(STDOUT_FILENO,x,strlen(x));
    }

    return 0;
}
