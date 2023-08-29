#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/file.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    int fd = open("ticketReservation.txt",O_RDWR);

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
        printf("Error in locking the file");
        return 0;
    }
    printf("Entered critical section\n");

    int buf;
    int num = read(fd,&buf,sizeof(int));
    buf++;
    printf("The ticket value is : %d\n",buf);

    lseek(fd,0,SEEK_SET);

    int ticket = write(fd,&buf,sizeof(int));
    if(ticket == -1){
        perror("errrrr");
        return 0;
    }
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    printf("Exit critical section\n");

    close(fd);
    return 0;
}


    