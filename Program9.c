#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    struct stat info;
    int val = stat(argv[1],&info);

    if(val < 0){
        perror("Error in reading stats of the file\n");
        return 0;
    }

    printf("inode_number %d \n", (int)info.st_ino);
    printf("number of hard links %d \n", (int)info.st_nlink);
    printf("user ID %d \n", (int)info.st_uid);
    printf("group ID %d \n", (int)info.st_gid);
    printf("size of file %d \n", (int)info.st_size);
    printf("block size %d \n", (int)info.st_blksize);
    printf("number of blocks %d \n", (int)info.st_blocks);
    printf("time of last access %d \n", (int)info.st_atime);
    printf("time of last modification %d \n", (int)info.st_mtime);
    printf("time of last change %d \n", (int)info.st_ctime);

    return 0;
}
