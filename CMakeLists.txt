cmake_minimum_required(VERSION 3.26)
project(Networking C)

set(CMAKE_C_STANDARD 23)

add_library(Networking
        Webserver/server.c
        Webserver/server.h
        test.c
        Webserver/HTTPRequest.c
        Webserver/HTTPRequest.h
        DataStructure/common/Node.h
        DataStructure/list/LinkedList.c
        DataStructure/list/LinkedList.h
        DataStructure/list/Queue.c
        DataStructure/list/Queue.h
        DataStructure/common/Node.c
        DataStructure/tree/BinarySearchTree.c
        DataStructure/tree/BinarySearchTree.h
)
