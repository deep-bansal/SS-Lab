/*
============================================================================
Name : 19.c
Author : Deep Bansal
Description : Write a program to find out time taken to execute getpid system call.
              Use time stamp counter.

Date: 4th Sept, 2023.
============================================================================
*/
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    pid_t process_id =  getpid();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Process ID is %d\n",process_id);
    printf("the time taken by getpid function is %f\n",cpu_time_used);

    
    return 0;
}



