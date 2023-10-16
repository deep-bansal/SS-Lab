/*
============================================================================
Name : 33.c
Author : Deep Bansal
Description : Write a program to communicate between two machines using socket.
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
    struct sockaddr_in address, client;
    char buffer[100];

    int socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_descriptor == -1)
    {
        perror("Error while creating socket!");
        return 0;
    }
    printf("Server side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8088);

    int bind_status = bind(socket_descriptor, (struct sockaddr *)&address, sizeof(address));
    if (bind_status == -1)
    {
        perror("Error while binding name to socket!");
        return 0;
    }
    printf("Binding to socket was successful!\n");

    int listen_status = listen(socket_descriptor, 2);
    if (listen_status == -1)
    {
        perror("Error while trying to listen for connections!");
        return 0;
    }
    printf("Now listening for connections on a socket!\n");

    int client_size = (int)sizeof(client);
    int connection_descriptor = accept(socket_descriptor, (struct sockaddr *)&client, &client_size);
    if (connection_descriptor == -1)
        perror("Error while accepting a connection!");
    else
    {
        int writeCount = write(connection_descriptor, "I'm the server!", 15);
        if (writeCount == -1)
            perror("Error while writing to network via socket!");
        else
            printf("Data sent to client!\n");

        int readCount = read(connection_descriptor, buffer, 100);
        if (readCount == -1)
            perror("Error while reading from network via socket!");
        else
            printf("Data from client: %s\n", buffer);

    }

    close(connection_descriptor);

    close(socket_descriptor);
}