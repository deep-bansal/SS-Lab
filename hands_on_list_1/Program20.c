/*
============================================================================
Name : 20.c
Author : Deep Bansal
Description : Find out the priority of your running program. Modify the priority with nice command.

Date: 4th Sept, 2023.
============================================================================
*/
#include <sys/time.h>
#include <sys/resource.h>
#include<stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int priority_of_process =  getpriority(PRIO_PROCESS, 0);
    if(priority_of_process == -1){
        perror("Error in getting process priority\n");
        return 0;
    }
    printf("Priority of current process is %d\n",priority_of_process);

    int new_priority = nice(10);
    if(new_priority == -1){
        perror("Error in setting new priority\n");
        return 0;
    }
    printf("Priority of current process after nice command is %d\n",new_priority);

    
    return 0;
}


       
