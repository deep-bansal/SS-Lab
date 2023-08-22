#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd_read = open(argv[1],O_WRONLY);
    if(fd_read == -1){
        printf("Error in opening the file");
        return 0;
    }
    int stats =  fcntl(fd_read, F_GETFL,0);

    int fflags = stats & O_ACCMODE;
    if(fflags == O_RDONLY)
    printf("opened in read only mode\n");
    else if (fflags == O_WRONLY)
    printf("opened in write only mode\n");
    else if (fflags = O_RDWR)
    printf("opened in read and write mode\n");

    int fd_read_close = close(fd_read);
       if(fd_read_close == -1){
        printf("totally useless");
    }

    return 0;
}


