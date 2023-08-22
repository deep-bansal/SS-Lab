#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc,char* argv[]){
       int file_read =  open(argv[1],O_RDONLY);

       if(file_read == -1){
         printf("File useless");
         return 0;
       }
       char buf;
       int char_read = read(file_read,&buf,1);
       int char_written;
      while(1)
      {
      while(buf != '\n'){
        char_written = write(STDOUT_FILENO,&buf,1);
        char_read = read(file_read,&buf,1);
      }
        char_written = write(STDOUT_FILENO,&buf,1);

      }

       int fd_read_close = close(file_read);
       if(fd_read_close == -1){
        printf("totally useless");
    }
}
