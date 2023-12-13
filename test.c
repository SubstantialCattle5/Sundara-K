//
// Created by nilay on 12/13/23.
//

#include "server.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void launch(struct Server *server) {
    char buffer[30000];
    while (1) {
        printf("====== WAITING FOR CONNECTION ========");
        int address_length = sizeof(server->address);
        int new_socket = accept(server->socket,(struct sockaddr *)&server->address , (socklen_t *)&address_length) ;
        read(new_socket,buffer,30000); // read the message from client and copy it in buffer
        printf("%s\n",buffer) ;

        char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nda main man!";
        write(new_socket,hello,strlen(hello));
        close(new_socket) ;
    }

};
int main() {
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 8080, 10, launch);
    printf("Server listening on port: %d\n", server.port);
    server.launch(&server);
}