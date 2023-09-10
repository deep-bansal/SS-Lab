/*
============================================================================
Name : 17a.c
Author : Deep Bansal
Description :Write a program to simulate online ticket reservation. Implement write lock
             Write a program to open a file, store a ticket number and exit. 
             Write a separate program, to open the file, implement write lock, read the ticket number,
             increment the number and print the new ticket number then close the file.

Date: 1st Sept, 2023.
============================================================================
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/file.h>
#include <sys/types.h>

int main(){
    int fd = open("ticketReservation.txt",O_WRONLY);

    if(fd == -1){
        perror("file not opening");
        return 1;
    }

    printf("Before applying exclusive lock\n");
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_whence = SEEK_SET;
    lock.l_pid = getpid();

    int lck = fcntl(fd,F_SETLKW,&lock);
    if(lck == -1){
        perror("Error in locking the file");
        return 0;
    }
    printf("Entered critical section\n");
    printf("Enter initial Random Ticket number: \n");

    int ticketNo;
    read(STDIN_FILENO,&ticketNo,sizeof(int));

    lseek(fd,0,SEEK_SET);
    int ticket = write(fd,&ticketNo,sizeof(int));
    if(ticket == -1){
        perror("errrrr");
        return 0;
    }
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    printf("Exit critical section\n");

    close(fd);

}