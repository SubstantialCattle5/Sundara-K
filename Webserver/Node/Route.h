//
// Created by nilay on 12/17/23.
//

#ifndef NETWORKING_ROUTE_H
#define NETWORKING_ROUTE_H

#include "../Protocols/HTTPRequest.h"
#include "HTTPServer.h"

struct Route
{
    int methods[9];
    char *uri;

    char *(*route_function)(struct HTTPServer *server, struct HTTPRequest *request);
};

#endif // NETWORKING_ROUTE_H
