/*
============================================================================
Name : 1b.c
Author : Deep Bansal
Description : Create the following types of a files using (ii) system call 
              b. hard link (link system call)
Date: 18th Aug, 2023.
============================================================================
*/

#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <stdlib.h>

int main(){
    int hard_link = link("file_to_link.txt","hard_link");
    if(hard_link == -1){
        perror("error in creating hard link\n");
        return 0;
    }
}