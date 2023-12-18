cmake_minimum_required(VERSION 3.26)
project(Networking C)

set(CMAKE_C_STANDARD 23)

add_library(Networking
        Webserver/Node/server.c
        Webserver/Node/server.h
        test.c
        Webserver/Protocols/HTTPRequest.c
        Webserver/Protocols/HTTPRequest.h
        DataStructure/common/Node.h
        DataStructure/list/LinkedList.c
        DataStructure/list/LinkedList.h
        DataStructure/list/Queue.c
        DataStructure/list/Queue.h
        DataStructure/common/Node.c
        DataStructure/tree/BinarySearchTree.c
        DataStructure/tree/BinarySearchTree.h
        DataStructure/Dictionary/Entry.h
        DataStructure/Dictionary/Entry.c
        DataStructure/Dictionary/Dictionary.h
        DataStructure/Dictionary/Dictionary.c
        Webserver/Node/HTTPServer.c
        Webserver/Node/HTTPServer.h
        Webserver/Node/Route.c
        Webserver/Node/Route.h
)
