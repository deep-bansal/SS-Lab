#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char buf[1024];
    int char_read = read(STDIN_FILENO,&buf,sizeof(buf));
    int cnt = 0;
    for (int i = 0; buf[i] != '\n'; i++)
    {
        cnt++;
    }
    buf[cnt] = '\n';
    int char_written = write(STDOUT_FILENO,&buf,cnt+1);


    return 0;
}
