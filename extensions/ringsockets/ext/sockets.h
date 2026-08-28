/*
    Modified    =>  Youssef Saeed (youssefelkholey@gmail.com)
    Date        =>  28-8-2026
    Changes     =>  Non-blocking I/O, select() support, sender address
                    storage (from/fromlen) and new function declarations.
*/

#ifndef ring_socket_h
#define ring_socket_h

#include "constants.h"


#if defined _WIN32
    #pragma once

    #include <winsock2.h>
    #include <WS2tcpip.h>

    #pragma comment (lib,"ws2_32.lib")
    #pragma comment (lib,"mswsock.lib")
    #pragma comment (lib,"advapi32.lib")


    #define CLOSESOCKET closesocket

    #define SOCKET_T SOCKET

#else
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <sys/select.h>
    #include <netinet/in.h>
    #include <netinet/tcp.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <netdb.h>

    #define CLOSESOCKET close

    #define SOCKET_T int

    #define INVALID_SOCKET (SOCKET_T)(~0)
    #define SOCKET_ERROR -1
    
#endif

#include <stdint.h>


typedef struct 
{
    SOCKET_T sockfd;
    struct addrinfo *addr;
    struct addrinfo hints;
    struct sockaddr_storage from;
    socklen_t fromlen;
} RING_SOCKET;



#include "ring.h"


void ring_vm_socket_init(void *pPointer);
void ring_vm_socket_fd(void *pPointer);
void ring_vm_socket_shutdown(void *pPointer);
void ring_vm_socket_setnonblocking(void *pPointer);
void ring_vm_socket_select(void *pPointer);
void ring_vm_socket_lasterror(void *pPointer);
void ring_vm_socket_getaddrinfo(void *pPointer);
void ring_vm_socket_getsockname(void *pPointer);
void ring_vm_socket_getpeername(void *pPointer);
void ring_vm_socket_socketpair(void *pPointer);
void ring_vm_socket_getprotobyname(void *pPointer);
void ring_vm_socket_setsockopt(void *pPointer);
void ring_vm_socket_getsockopt(void *pPointer);
void ring_vm_socket_bind(void *pPointer);
void ring_vm_socket_listen(void *pPointer);
void ring_vm_socket_accept(void *pPointer);
void ring_vm_socket_send(void *pPointer);
void ring_vm_socket_sendto(void *pPointer);
void ring_vm_socket_recv(void *pPointer);
void ring_vm_socket_recvfrom(void *pPointer);
void ring_vm_socket_connect(void *pPointer);
void ring_vm_socket_close(void *pPointer);
void ring_vm_socket_gethostname(void *pPointer);
void ring_vm_socket_gethostbyname(void *pPointer);
void ring_vm_socket_gethostbyaddr(void *pPointer);
void ring_vm_socket_getservbyname(void *pPointer);
void ring_vm_socket_getservbyport(void *pPointer);
void ring_vm_socket_ntohs(void *pPointer);
void ring_vm_socket_ntohl(void *pPointer);
void ring_vm_socket_htonl(void *pPointer);
void ring_vm_socket_htons(void *pPointer);
void ring_vm_socket_inet_addr(void *pPointer);
void ring_vm_socket_inet_ntoa(void *pPointer);
void ring_vm_socket_inet_pton(void *pPointer);
void ring_vm_socket_inet_ntop(void *pPointer);

void ring_vm_socket_cleanup(void *pPointer);

RING_API void ringlib_init(RingState *pRingState);

// MACRO
#define RING_VM_POINTER_SOCKET "socket"

#endif


