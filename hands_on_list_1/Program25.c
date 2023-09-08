/*
============================================================================
Name : 25.c
Author : Deep Bansal
Description :  Write a program to create three child processes. 
               The parent should wait for a particular child (use waitpid system call).
Date: 4th Sept, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    pid_t child1 = fork();

    if(child1 == -1){
        perror("Error in creating child1 process\n");
        return 0;
    }

    if(child1 > 0){
        int child2 = fork();
        if(child2 == -1){
            perror("Error in creating child2 process\n");
            return 0;
        }

        if(child2 > 0){
            int status2;
            int x = waitpid(child2,&status2,0);
            if(x == -1){
                perror("error in waiting for child 2 completion\n");
                return 0;
            }
            printf("The value of ID returned by waitpid is %d\n",x);

            int child3 = fork();
             if(child3 == -1){
                perror("Error in creating child3 process\n");
                return 0;
            }

            if(child3 > 0 ){
                int status3;
                int x = waitpid(child3,&status3,0);
                if(x == -1){
                    perror("error in waiting for child 3 completion\n");
                    return 0;
                }
                printf("The value of ID returned by waitpid is %d\n",x);

            }
            else{
                printf("Child 3 Pid is %d\n",getpid());
            }

        }else{
            printf("Child 2 Pid is %d\n",getpid());
        }    
    }else{
        printf("Child 1 Pid is %d\n",getpid());
    }






    
    return 0;
}
