//
// Created by nilay on 12/20/23.
//

#include "HTTPServer.h"
#include "Route.h"
#include <stdarg.h>
#include <string.h>

// prototype
void register_routes(struct HTTPServer *server, char * (*route_function)(struct HTTPServer *server, struct HTTPRequest *request), char *uri, int num_methods, ...);

void launch (struct Server *);

struct HTTPServer http_server_constructor() {
    const int PORT = 8080;
    struct HTTPServer server ;
    server.server = server_constructor(AF_INET, SOCK_STREAM,0,INADDR_ANY, PORT, 255 , launch);
    server.routes = dictionary_constructor(compare_string_keys) ;
    server.register_routes = register_routes ;

    return server ;
};


void register_routes(struct HTTPServer *server, char * (*route_function)(struct HTTPServer *server, struct HTTPRequest *request), char *uri, int num_methods, ...)
{
    struct Route route;
    va_list methods;
    va_start(methods, num_methods);
    for (int i = 0; i < num_methods; i++)
    {
        route.methods[i] = va_arg(methods, int);
    }
    strcpy(route.uri, uri);
    route.route_function = route_function;

    server->routes.insert(&server->routes, uri, sizeof(char[strlen(uri)]), &route, sizeof(route));
}

