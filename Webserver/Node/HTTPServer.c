//
// Created by nilay on 12/16/23.
//

#include "HTTPServer.h"
#include "../Protocols/HTTPRequest.h"

#include <unistd.h>
#include <string.h>
#include <stdio.h>
void launch(struct Server *server){
    int addrlen = sizeof(server->address) ;
    long valread;

    while(1)
    {
        printf("=== WAITING ===\n");
        int new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&addrlen);
        printf("New socket: %d\n", new_socket);
        char buffer[30000];
        valread = read(new_socket, buffer, 30000); // read the msg from the client and copy it to the buffer
        struct HTTPRequest request = http_request_constructor(buffer);
        char *x = "Host";
        char *Host = request.http_request_search(&request, x);
        // print all the contents of request header request
        printf("\n\n uri HTTP Server -> \n\n%s" , Host) ;
        char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\n";
        char *hello2 = "<h1>Hello world!</h1>";
        char *hello3 = "Hello world!\n";
        char r[strlen(Host) + strlen(hello2)];
        strcat(r, Host);
        strcat(r, hello2);
        write(new_socket, r, strlen(r));
        printf("\n\nrequest -> \n\n%s" , buffer) ;
        close(new_socket);
    }
}