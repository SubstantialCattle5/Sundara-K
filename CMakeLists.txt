cmake_minimum_required(VERSION 3.26)
project(Networking C)

set(CMAKE_C_STANDARD 23)

add_library(Networking
        server.c
        server.h
        test.c
        HTTPRequest.c
        HTTPRequest.h)
