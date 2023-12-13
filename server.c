//
// Created by nilay on 12/13/23.
// Implementation file

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void(*launch)(struct Server *server)){
    struct Server server ;

    server.domain = domain ;
    server.service = service ;
    server.protocol = protocol ;
    server.interface = interface ;
    server.port = port ;
    server.backlog = backlog ;

    // Creating address
    server.address.sin_family = domain;
    server.address.sin_port = htons(port);   // converting int port into bytes that would refer to a network port
    server.address.sin_addr.s_addr = htonl(interface);

    // creates  an endpoint for communication
    server.socket = socket(domain,service,protocol) ;

    if (server.socket == 0){
        perror("Failed to connect.......\n");
        exit(1);
    }

    if ((bind(server.socket,(struct sockaddr *)&server.address, sizeof(server.address))) < 0){
        perror("Failed to blind socket ........\n");
        exit(1);
    }

    if ((listen(server.socket,server.backlog))<0) {
        perror("Failed to start listening..... \n");
        exit(1);
    };

    server.launch = launch ;

    return server ;
}