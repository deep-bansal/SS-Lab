/*
============================================================================
Name : 29.c
Author : Deep Bansal
Description : Write a program to get scheduling policy and modify the scheduling policy
             (SCHED_FIFO, SCHED_RR).
Date: 4th Sept, 2023.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(int argc, char const *argv[])
{
    int schd = sched_getscheduler(getpid());
    if(schd == -1){
        perror("error in retriving scheduled policy\n");
        return 0;
    }

    switch (schd)
    {
        case SCHED_FIFO:
            printf("Scheduled policy is FIFO policy\n");
            break;
        
        case SCHED_RR:
            printf("Scheduled policy is RR policy\n");
            break;

        case SCHED_OTHER:
            printf("Scheduled policy is OTHER policy\n");
            break;
        
        default:
            printf("Scheduled policy is unknown\n");
            break;
    }

    struct sched_param param;
    param.sched_priority = 99;

    int new_policy = sched_setscheduler(getpid(),SCHED_FIFO,&param);

    if(new_policy == -1){
        perror("error in setting new schedule policy\n");
        return 0;
    }

    int new_policy_set = sched_getscheduler(getpid());

    switch (new_policy_set)
    {
        case SCHED_FIFO:
            printf("Scheduled policy is FIFO policy\n");
            break;
        
        case SCHED_RR:
            printf("Scheduled policy is RR policy\n");
            break;

        case SCHED_OTHER:
            printf("Scheduled policy is OTHER policy\n");
            break;
        
        default:
            printf("Scheduled policy is unknown\n");
            break;
    }

    
    return 0;
}
