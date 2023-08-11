#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = creat("sample.txt", S_IRUSR | S_IWUSR);
    
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }
    
    printf("File created successfully with file descriptor: %d\n", fd);
    
    close(fd);

    return 0;
}
