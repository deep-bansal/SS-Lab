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
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int socket_descriptor;

void handle_client(int client_socket) {
    char buffer[100];
    int writeCount = write(client_socket, "I'm the server!", 15);
    if (writeCount == -1) {
        perror("Error while writing to network via socket!");
        close(client_socket);
        return;
    }
    printf("Data sent to client!\n");

    int readCount = read(client_socket, buffer, sizeof(buffer));
    if (readCount == -1) {
        perror("Error while reading from network via socket!");
        close(client_socket);
        return;
    }
    buffer[readCount] = '\0';
    printf("Data from client: %s\n", buffer);

    close(client_socket);
}

int main() {
    struct sockaddr_in address, client;
    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    
    if (socket_descriptor == -1) {
        perror("Error while creating socket!");
        return 1;
    }
    printf("Server side socket successfully created!\n");

    // socket creation done successfully

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8088);

    int bind_status = bind(socket_descriptor, (struct sockaddr *)&address, sizeof(address));
    if (bind_status == -1) {
        perror("Error while binding name to socket!");
        return 1;
    }
    printf("Binding to socket was successful!\n");

    // binding performed successfully

    int listen_status = listen(socket_descriptor, 2);
    if (listen_status == -1) {
        perror("Error while trying to listen for connections!");
        return 1;
    }
    printf("Now listening for connections on a socket!\n");

    while (1) {
        int client_size = sizeof(client);
        int connection_descriptor = accept(socket_descriptor, (struct sockaddr *)&client, &client_size);

        if (connection_descriptor == -1) {
            perror("Error while accepting a connection!");
            continue;
        }

        // Create a new process to handle the client connection
        pid_t pid = fork();

        if (pid == -1) {
            perror("Error while forking a process for the client connection");
            close(connection_descriptor);
            continue;
        }

        if (pid == 0) {
            // This is the child process
            close(socket_descriptor); // Close the listening socket in the child

            handle_client(connection_descriptor);

            return 0; 
        } else {
            // This is the parent process (listening)
            close(connection_descriptor); // Close the connection descriptor in the parent
        }
    }

    close(socket_descriptor);

    return 0;
}
