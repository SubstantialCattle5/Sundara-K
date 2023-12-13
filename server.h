//
// Created by nilay on 12/13/23.
//

#ifndef NETWORKING_SERVER_H
#define NETWORKING_SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>

struct Server {
    int domain ;
    int service ;
    int protocol ;
    u_long interface ;
    int port ;
    int backlog ;

    //* TODO : Check if the server is truly portable since ipv4 and ipv6 has different structs
    struct sockaddr_in address;

    void(*launch)(struct Server *server) ;

    int socket ;
};

struct Server server_constructor(int domain , int service, int protocol , u_long interface ,int port ,int backlog , void(*launch)(struct Server *server));

#endif //NETWORKING_SERVER_H
