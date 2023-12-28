
#include "../Networking/Webserver/Node/HTTPServer.h"

char * home(struct HTTPServer *server, struct HTTPRequest *request)
{
    char *x = render_template(2, "/home/nilay/Documents/demo/header.html", "/home/nilay/Documents/demo/header.html");
    return x;
}

char * about(struct HTTPServer *server, struct HTTPRequest *request)
{
    return render_template(2, "/home/nilay/Documents/demo/header.html", "/home/nilay/Documents/demo/header.html");
}

int main()
{
    struct HTTPServer server = http_server_constructor();

    server.register_routes(&server, home, "/", 0);
    server.register_routes(&server, about, "/about", 0);

    server.launch(&server);
}