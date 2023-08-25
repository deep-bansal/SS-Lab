#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc,char* argv[]){
       int file_read =  open(argv[1],O_RDONLY);

       if(file_read == -1){
         perror("File not opening");
         return 0;
       }
       char buf[256];
       int lineIndex = 0;
       char line[256];
       int bytesRead;
       while((bytesRead = read(file_read,buf,sizeof(buf))) > 0){
        for (int i = 0; i < bytesRead; i++)
        {
          if(buf[i] == '\n'){
            line[lineIndex] = '\0';
            printf("%s\n",line);
            lineIndex = 0;
          }
          else{
            line[lineIndex++] = buf[i];
          }
        }
       }

       int fd_read_close = close(file_read);
       if(fd_read_close == -1){
        printf("file not closing ");
    }
}