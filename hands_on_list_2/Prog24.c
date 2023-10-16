/*
============================================================================
Name : 24.c
Author : Deep Bansal
Description : Write a program to create a message queue and print the key 
              and message queue id.
Date: 8th Sept, 2023.
============================================================================
*/

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>  
#include <stdio.h>  
#include <unistd.h>  
#include <errno.h>  

int main()
{
    int queue_key = ftok(".", 1);

    if (queue_key == -1)
    {
        perror("Error while computing key!");
        return 0;
    }

    int q_identifier = msgget(queue_key, IPC_CREAT | IPC_EXCL | 0700);
    if (q_identifier == -1)
    {
        perror("Error while creating Message Queue!");
        return 0;
    }

    printf("Key: %d\n", queue_key);
    printf("Message Queue Identifier: %d\n", q_identifier);     
}