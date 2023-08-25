#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(){
    int fd = open("sample.txt",O_WRONLY);

    if(fd == -1){
        printf("useless file");
        return 1;
    }
    // printf("Before entering critical section...\n");
    // struct flock lock;
    // memset(&lock,0,sizeof(lock));
    // lock.l_type = F_WRLCK;
    // // lock.l_start = 0;
    // // lock.l_len = sizeof(fd);
    // // lock.l_whence = 0;
    // // lock.l_pid = getpid();

    // int lck = fcntl(fd,F_SETLKW,&lock);
    // printf("Entered critical section...\n");
    // getchar();


    // lock.l_type = F_UNLCK;
    // fcntl(fd,F_SETLK,&lock);
    // printf("outside critical section...\n");

    printf("Before entering critical section...\n");
    struct flock lock;
    memset(&lock,0,sizeof(lock));
    lock.l_type = F_RDLCK;
    // lock.l_start = 0;
    // lock.l_len = sizeof(fd);
    // lock.l_whence = 0;
    // lock.l_pid = getpid();

    int lck = fcntl(fd,F_SETLKW,&lock);
    printf("Entered critical section...\n");
    getchar();


    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    printf("outside critical section...\n");

    close(fd);

}