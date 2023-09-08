/*
============================================================================
Name : 16a.c
Author : Deep Bansal
Description :Write a program to perform mandatory locking. 
             a. Implement write lock

Date: 1st Sept, 2023.
============================================================================
*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(){
    int fd = open("sample.txt",O_WRONLY);

    if(fd == -1){
        perror("useless file");
        return 1;
    }
     printf("Before entering critical section...\n");
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_whence = SEEK_SET;
    lock.l_pid = getpid();

    int lck = fcntl(fd,F_SETLKW,&lock);
    printf("Entered critical section...\n");
    getchar();


    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    printf("outside critical section...\n");

    // printf("Before entering critical section...\n");
    // struct flock lock;
    // memset(&lock,0,sizeof(lock));
    // lock.l_type = F_RDLCK;
    // // lock.l_start = 0;
    // // lock.l_len = 0;
    // // lock.l_whence = SEEK_SET;
    // // lock.l_pid = getpid();

    // int lck = fcntl(fd,F_SETLKW,&lock);
    // printf("Entered critical section...\n");
    // getchar();


    // lock.l_type = F_UNLCK;
    // fcntl(fd,F_SETLK,&lock);
    // printf("outside critical section...\n");

    close(fd);

}