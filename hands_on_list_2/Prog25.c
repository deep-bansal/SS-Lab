/*
============================================================================
Name : 25.c
Author : Deep Bansal
Description :  Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
                a. access permission
                b. uid, gid
                c. time of last message sent and received
                d. time of last change in the message queue
                d. size of the queue
                f. number of messages in the queue
                g. maximum number of bytes allowed
                h. pid of the msgsnd and msgrcv
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

    struct msqid_ds msg_queue;
           
    int msgctlStatus = msgctl(q_identifier, IPC_STAT, &msg_queue);

    if (msgctlStatus == -1)
    {
        perror("Error while getting Message Queue info!");
        _exit(0);
    }

    printf("Access Permission: %d\n", msg_queue.msg_perm.mode);
    printf("UID: %d\n", msg_queue.msg_perm.uid);
    printf("GID: %d\n", msg_queue.msg_perm.gid);
    printf("Time of last message sent: %ld\n", msg_queue.msg_stime);
    printf("Time of last message received: %ld\n", msg_queue.msg_rtime);
    printf("Size of queue: %ld\n", msg_queue.__msg_cbytes);
    printf("Number of messages in the queue: %ld\n", msg_queue.msg_qnum);
    printf("Maximum number of bytes allowed in the queue: %ld\n", msg_queue.msg_qbytes);
    printf("PID of last sent message: %d\n", msg_queue.msg_lspid);
    printf("PID of last received message: %d\n", msg_queue.msg_lrpid);       
}