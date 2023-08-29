#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int fd;

    fd = open("sample.txt", O_RDWR | O_EXCL);

    if (fd == -1) {
        if (errno == EEXIST) {
            perror("File already exists. Opening in read-write mode.\n");
        } else {
            perror("Error opening file");
            return 1;
        }
    } else {
        printf("File opened successfully in read-write mode.\n");
    }

    

    // Close the file
    close(fd);

    return 0;
}
