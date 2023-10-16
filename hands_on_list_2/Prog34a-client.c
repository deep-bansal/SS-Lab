/*
============================================================================
Name : 34a.c
Author : Deep Bansal
Description : Write a program to create a concurrent server.
              a. use fork
Date: 15th Sept, 2023.
============================================================================
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h> 
#include <stdio.h>      
#include <unistd.h>     

int main()
{
    struct sockaddr_in address; 
    char buffer[100];

    int socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_descriptor == -1)
    {
        perror("Error while creating socket!");
        return 0;
    }
    printf("Client side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8088);

    int connect_status = connect(socket_descriptor, (struct sockaddr *)&address, sizeof(address));
    if (connect_status == -1)
    {
        perror("Error while connecting to server!");
        return 0;
    }
    printf("Client to server connection successfully established!\n");

    int readCount = read(socket_descriptor, buffer, 100);
    ;
    if (readCount == -1)
        perror("Error while reading from network via socket!");
    else
        printf("Data from server: %s\n", buffer);

    int writeCount = write(socket_descriptor, "I'm the client!", 15);
    if (writeCount == -1)
        perror("Error while writing to network via socket!");
    else
        printf("Data sent to server!");

    close(socket_descriptor);
}