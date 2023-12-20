/*
 * Declaration of Servers , Server Constructor
 * This file is part of the Networking Library.
 *
 * Created By - Nilay Nath Sharan
 * 15th Dec,2023
 *
 * */



#ifndef NETWORKING_SERVER_H
#define NETWORKING_SERVER_H


#include <sys/socket.h>
#include <netinet/in.h>

struct Server {
    // AF_INET or AF_INET6 used for ipv4 and ipv6 respectively. AF_INET6 is not supported yet
    int domain ;

    /*
    * Service can be a socket type or socket family
    * SOCK_STREAM for TCP/FTP - 1  use socket.h constant SOCK_STREAM
    * SOCK_DGRAM for UDP - 2 use socket.h constant SOCK_DGRAM
    * SOCK_RAW for raw sockets 
    * SOCK_RDM for reliable datagram sockets 
    * SOCK_SEQPACKET for sequenced-packet sockets
    * SOCK_DCCP for Datagram Congestion Control Protocol sockets
    * SOCK_PACKET for Linux specific way of getting packets at the device driver level. For writing rarp and other similar things on the user level.
    * */
    int service ;

    /* 
     * Protocol can be a specific protocol to be used with the socket
     * IPPROTO_TCP for TCP - 6
     * IPPROTO_UDP for UDP - 17
     * IPPROTO_SCTP for SCTP - 132
     * IPPROTO_TIPC for TIPC - 30 (Not supported yet) 
     * */
    int protocol ;

    /*
    * Interface is the ip address of the interface to be used for the server
    * INADDR_ANY for any interface
    * INADDR_LOOPBACK for loopback interface
    * INADDR_BROADCAST for broadcast interface
    * INADDR_NONE for no interface
    */
    u_long interface ;

    /*
    * Port is the port number to be used for the server
    * Use port number greater than 1024
    * Don't use port number 80,443,20,21,22,23,25,53,110,143,161,162,389,443,636,989,990,3389 as they are reserved for other protocols
    */
    int port ;
    
    /*
    * Backlog is the maximum number of connections that can be queued for the server
    */
    int backlog ;

    /*
    * Address is the address of the server
    * Address is a struct sockaddr_in for ipv4 and struct sockaddr_in6 for ipv6
    * Note - Need to check if the server is truly portable
    */
    struct sockaddr_in address;

    /*
    * Launch is the function that is called when the server is launched
    * Launch is a function pointer to a function that takes a struct Server pointer as an argument and returns void
    * The function should be defined as void launch(struct Server *server) and should be defined in the main file
    */
    void(*launch)(struct Server *server) ;

    /*
    * Socket is the socket descriptor of the server
    */
    int socket ;
};

/*
* server_constructor is a constructor function for the struct Server 
* Meant to be used to create a struct Server object
* Takes the following arguments
* domain - int - AF_INET or AF_INET6 used for ipv4 and ipv6 respectively. AF_INET6 is not supported yet
* service - int - Service can be a socket type or socket family
* protocol - int - Protocol can be a specific protocol to be used with the socket
* interface - u_long - Interface is the ip address of the interface to be used for the server
* port - int - Port is the port number to be used for the server
* backlog - int - Backlog is the maximum number of connections that can be queued for the server
* launch - void(*)(struct Server *server) - Launch is the function that is called when the server is launched
* Returns a struct Server object
*/
struct Server server_constructor(int domain , int service, int protocol , u_long interface ,int port ,int backlog , void(*launch)(struct Server *server));



#endif //NETWORKING_SERVER_H
