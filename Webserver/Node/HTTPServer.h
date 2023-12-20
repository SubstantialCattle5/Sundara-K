//
// Created by nilay on 12/20/23.
//

#ifndef NETWORKING_HTTPSERVER_H
#define NETWORKING_HTTPSERVER_H

#include "server.h"
#include "../Protocols/HTTPRequest.h"

struct HTTPServer {
    struct Server server ;

    void (*register_routes)(struct HTTPServer *server, char *(*route_function)(struct HTTPServer *server, struct HTTPRequest *request), char *uri, int num_methods, ...);

    struct Dictionary routes;
};


struct HTTPServer http_server_constructor(void) ;


#endif //NETWORKING_HTTPSERVER_H
