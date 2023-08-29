#include <unistd.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

int main(){

    int i = 0;
    while(environ[i]) {
        size_t x = strlen(environ[i]);
        write(STDOUT_FILENO,environ[i],x);
        char* y = "\n";
        i++;
        write(STDOUT_FILENO,y,strlen(y));
    }
}