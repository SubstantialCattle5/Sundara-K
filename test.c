#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "Webserver/Node/server.h"
#include "Webserver/Node/HTTPServer.h"


int main()
{
    const int PORT = 8000 ; 
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, PORT, 20, launch);
    server.launch(&server);
}
