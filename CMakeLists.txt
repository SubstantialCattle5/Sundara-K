cmake_minimum_required(VERSION 3.26)
project(Networking C)

set(CMAKE_C_STANDARD 23)

add_library(Networking
        Webserver/server.c
        Webserver/server.h
        test.c
        Webserver/HTTPRequest.c
        Webserver/HTTPRequest.h
        DataStructure/Node.h
        DataStructure/LinkedList.c
        DataStructure/LinkedList.h
        DataStructure/Queue.c
        DataStructure/Queue.h
        DataStructure/Node.c
)
