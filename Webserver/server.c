/*
*  This file contains the implementation of the server
*  Part of the Networking Library.
*
*  Input :
*  Server constructor takes the following parameters
*  domain - int - AF_INET or AF_INET6 used for ipv4 and ipv6 respectively. AF_INET6 is not supported yet
*  service - int - Service can be a socket type or socket family
*  protocol - int - Protocol can be a specific protocol to be used with the socket
*  interface - u_long - Interface is the ip address of the interface to be used for the server
*  port - int - Port is the port number to be used for the server
*  backlog - int - Backlog is the maximum number of connections that can be queued for the server
*  launch - void(*)(struct Server *server) - Launch is the function that is called when the server is launched
*
*  Output :
*  Returns a struct Server object
*
*  Created By - Nilay Nath Sharan
*  15th December 2023.
* */

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Constructor for the server
* @param domain - AF_INET or AF_INET6 used for ipv4 and ipv6 respectively. AF_INET6 is not supported yet
* @param service - Service can be a socket type or socket family. use socket.h constant SOCK_STREAM for TCP/FTP - 1 and SOCK_DGRAM for UDP - 2
* @param protocol - Protocol can be a specific protocol to be used with the socket
* @param interface - Interface is the ip address of the interface to be used for the server
* @param port - Port is the port number to be used for the server
* @param backlog - Maximum number of connections to be queued
* @param launch - Function to be called when the server is launched
* @return server - Returns the server object
*/
struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void(*launch)(struct Server *server)){
    struct Server server ;

    server.domain = domain ;
    server.service = service ;
    server.protocol = protocol ;
    server.interface = interface ;
    server.port = port ;
    server.backlog = backlog ;

    /* Creating the servers address
    * struct sockaddr_in {
    *     short            sin_family;   // e.g. AF_INET, AF_INET6
    *     unsigned short   sin_port;     // e.g. htons(3490)
    *     struct in_addr   sin_addr;     // see struct in_addr, below
    *     char             sin_zero[8];  // zero this if you want to
    *     } ;
    */
    server.address.sin_family = domain;
    server.address.sin_port = htons(port);   // converting int port into bytes that would refer to a network port
    server.address.sin_addr.s_addr = htonl(interface); // converting int interface into bytes that would refer to a network interface

    // Creating socket for the server
    server.socket = socket(domain,service,protocol) ;

    /*
    * To check if the socket was created successfully
    * Note : add better error handling
    */
    if (server.socket == 0){
        perror("Failed to connect.......\n");
        exit(1);
    }


    /*
    * Give the socket FD the local address ADDR (which is LEN bytes long).
    * Returns 0 on success, -1 for errors.
    * bind() assigns the address specified by addr to the socket referred to by the file descriptor sockfd.
    * Note : add better error handling
    */
    if ((bind(server.socket,(struct sockaddr *)&server.address, sizeof(server.address))) < 0){
        perror("Failed to blind socket ........\n");
        exit(1);
    }

    if ((listen(server.socket,server.backlog))<0) {
        perror("Failed to start listening..... \n");
        exit(1);
    };

    server.launch = launch ;

    return server ;
}