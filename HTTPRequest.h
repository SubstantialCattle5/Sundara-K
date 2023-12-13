//
// Created by nilay on 12/13/23.
//

#ifndef NETWORKING_HTTPREQUEST_H
#define NETWORKING_HTTPREQUEST_H

enum HTTPMethods {
    GET,
    POST,
    PUT,
    HEAD,
    PATCH,
    DELETE,
    CONNECT,
    OPTIONS,
    TRACE
};

struct HTTPRequest {
    int Method;
    char  *URI;
    float HTTPVersion;
};

struct HTTPRequest http_request_constructor(char *request_string) ;

#endif //NETWORKING_HTTPREQUEST_H
