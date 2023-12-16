#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "Webserver/Node/server.h"
#include "Webserver/Protocols/HTTPRequest.h"

void launch(struct Server *server)
{
    char buffer[30000];
    while (1)
    {
        printf("====== WAITING FOR CONNECTION ========\n");
        int address_length = sizeof(server->address);
        int new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&address_length);
        read(new_socket, buffer, 30000); // read the message from client and copy it in buffer
        printf("====== RECEIVED HTTP REQUEST ========\n"
               "%s\n",
               buffer);
        // Parse received data into an HTTPRequest struct

        // Example: Display parsed HTTP request information



        char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nda main man!";
        write(new_socket, hello, strlen(hello));
        close(new_socket);
    }
}
int main()
{
    const int PORT = 8000;
    // constructing a server
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, PORT, 10, launch);

    printf("Listening on the port: %d\n", server.port);
    server.launch(&server);
}
