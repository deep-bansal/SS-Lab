#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd = open("sample.txt",O_RDWR);
    if(fd == -1){
        perror("File opening error");
        return 0;
    }

    char buf[10];
    for(int i = 0; i < 10; i++){
        read(STDIN_FILENO,&buf[i],1);
    }

    int content_write = write(fd,&buf,sizeof(buf));
    if(content_write == -1){
        printf("Error in writing the data");
        return 0;
    }
    int seek = lseek(fd,10,SEEK_SET);
    // printf("%d",seek);
    for(int i = 0; i < 10; i++){
        read(STDIN_FILENO,&buf[i],1);
    }

    content_write = write(fd,&buf,sizeof(buf));
    if(content_write == -1){
        printf("Error in writing the data");
        return 0;
    }

    close(fd);    
    return 0;
}
