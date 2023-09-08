// Write a program to create five new files with infinite loop.
// Execute the program in the background and check the file descriptor table at /proc/pid/fd.

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int fd_of_files[5];
    fd_of_files[0] = open("/home/parallels/sslab/prog5files/file1", O_RDWR | O_CREAT | O_EXCL);
    fd_of_files[1] = open("/home/parallels/sslab/prog5files/file2", O_RDWR | O_CREAT | O_EXCL);
    fd_of_files[2] = open("/home/parallels/sslab/prog5files/file3", O_RDWR | O_CREAT | O_EXCL);
    fd_of_files[3] = open("/home/parallels/sslab/prog5files/file4", O_RDWR | O_CREAT | O_EXCL);
    fd_of_files[4] = open("/home/parallels/sslab/prog5files/file5", O_RDWR | O_CREAT | O_EXCL);
    int cnt = 4;
    while (cnt != -1)
    {
        if (fd_of_files[cnt] == -1) {
            perror("Error opening or creating file");
            return 1;
        }
        cnt--;
    }
    
    getchar();
    
    return 0;
}



