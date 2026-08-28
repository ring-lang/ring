/*
    Author      =>  Abdallah Mohamed Elsharif
    Email       =>  elsharifabdallah53@gmail.com
    Date        =>  4-12-2020
*/

/*
	Modified for MonoRing integration.
	Mounir IDRASSI (mounir@idrix.fr)
	April 30th 2022
*/

/*
	Extended with non-blocking I/O, select() and additional
	functions, constants and bug fixes.
	Youssef Saeed (youssefelkholey@gmail.com)
	August 28th 2026
*/

#if defined _WIN32
	#define WIN32_LEAN_AND_MEAN
#endif

#include "sockets.h"

#ifdef _WIN32
BOOL g_bWinsockInitialized = FALSE;
#endif

static int ring_vm_socket_wouldblock(void);

void ring_vm_socket_init(void *pPointer) {
    RING_SOCKET *sock;
    int nProto = 0;

#ifdef _WIN32
    if (!g_bWinsockInitialized) {
		RING_API_ERROR("WSAStartup Failed");
		return;
	}
#endif

    if(RING_API_PARACOUNT < 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    } 

    if(!(RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    if(RING_API_PARACOUNT == 3) {
        if(!RING_API_ISNUMBER(3)) {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }

        nProto = (int) RING_API_GETNUMBER(3);
    }

    if(!(sock = (RING_SOCKET *) RING_API_MALLOC(sizeof(RING_SOCKET))))
    {
        RING_API_ERROR(RING_OOM);
        return;
    }


    sock->addr = NULL;
    memset(&sock->from, 0, sizeof(sock->from));
    sock->fromlen = 0;
	memset(&sock->hints, 0, sizeof(sock->hints));
    sock->sockfd = INVALID_SOCKET;
    sock->hints.ai_family = (int) RING_API_GETNUMBER(1);
    sock->hints.ai_socktype = (int) RING_API_GETNUMBER(2);
    sock->hints.ai_protocol = nProto;
    sock->hints.ai_flags = AI_PASSIVE;
    sock->hints.ai_canonname = NULL;
    sock->hints.ai_addr = NULL;
    sock->hints.ai_next = NULL;
    
    if((sock->sockfd = socket(sock->hints.ai_family, sock->hints.ai_socktype, sock->hints.ai_protocol)) == INVALID_SOCKET) {
        RING_API_ERROR("Sock Init Failed");
		RING_API_FREE(sock);
        return;
    }
    
    RING_API_RETCPOINTER(sock, RING_VM_POINTER_SOCKET);
    
}

void ring_vm_socket_fd(void *pPointer) {
    RING_SOCKET *sock;

    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);
    RING_API_RETNUMBER((int) sock->sockfd);
}

void ring_vm_socket_setsockopt(void *pPointer) {

    RING_SOCKET *sock;
    int level, optname, value;

#ifdef _WIN32
	if (!g_bWinsockInitialized) {
		RING_API_ERROR("WSAStartup failed");
		return;
	}
#endif

    if(RING_API_PARACOUNT != 4) 
    {
        RING_API_ERROR(RING_API_MISS4PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISNUMBER(2) && RING_API_ISNUMBER(3) && RING_API_ISNUMBER(4)))
    {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);
    level = RING_API_GETNUMBER(2);
    optname = RING_API_GETNUMBER(3);
    value = RING_API_GETNUMBER(4);

    if(setsockopt(sock->sockfd, level, optname, (const char *)&value, sizeof(value))) 
    {
        RING_API_ERROR("Set Socket Option Failed");
        return;
    }

}

void ring_vm_socket_getsockopt(void *pPointer) {

    RING_SOCKET *sock;
    int level, optname, buffer = 0;
    socklen_t valsize;

#ifdef _WIN32
	if (!g_bWinsockInitialized) {
		RING_API_ERROR("WSAStartup failed");
		return;
	}
#endif

    if(RING_API_PARACOUNT != 3) 
    {
        RING_API_ERROR(RING_API_MISS3PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISNUMBER(2) && RING_API_ISNUMBER(3)))
    {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);
    level = RING_API_GETNUMBER(2);
    optname = RING_API_GETNUMBER(3);
    valsize = sizeof(buffer);

    if(getsockopt(sock->sockfd, level, optname, (char *)&buffer, &valsize)) 
    {
        RING_API_ERROR("Get Socket option Failed");
        return;
    }

    RING_API_RETNUMBER(buffer);
}

void ring_vm_socket_bind(void *pPointer) {

    RING_SOCKET *sock;
    char cPort[6] = {0};

    if(RING_API_PARACOUNT != 3) {
        RING_API_ERROR(RING_API_MISS3PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISNUMBER(3))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);

    /* Read port number in string */
    snprintf(cPort, 6, "%d", (int) RING_API_GETNUMBER(3));

    if(getaddrinfo(RING_API_GETSTRING(2), cPort, &sock->hints, &sock->addr) != 0) {
        RING_API_ERROR("getaddrinfo Failed");
        return;
    }

    {
        struct addrinfo *rp;
        int bound = 0;

        for(rp = sock->addr; rp != NULL; rp = rp->ai_next) {
            if(bind(sock->sockfd, rp->ai_addr, rp->ai_addrlen) != SOCKET_ERROR) {
                bound = 1;
                break;
            }
        }

        if(!bound) {
            RING_API_ERROR("Bind Error");
            freeaddrinfo(sock->addr);
            sock->addr = NULL;
            return;
        }
    }

}

void ring_vm_socket_listen(void *pPointer) {
 
    RING_SOCKET *sock;
    int n;


    if(RING_API_PARACOUNT < 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    if(RING_API_PARACOUNT == 1)
        n = 5;

    else {

        if(RING_API_ISNUMBER(2))
            n = (int) RING_API_GETNUMBER(2);
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }

    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);

    if(listen(sock->sockfd, n) == SOCKET_ERROR) {
        RING_API_ERROR("Listen Failed");
        return;
    }
 
}

void ring_vm_socket_accept(void *pPointer) {

    RING_SOCKET *sock, *newsock;
    struct sockaddr_storage clientaddr;
    socklen_t nSize;

    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);
    
    if(!(newsock = (RING_SOCKET *) RING_API_MALLOC(sizeof(RING_SOCKET))))
    {
        RING_API_ERROR(RING_OOM);
        return;
    }

    newsock->addr = NULL;
    memset(&newsock->from, 0, sizeof(newsock->from));
    newsock->fromlen = 0;

    nSize = sizeof(clientaddr);

    newsock->sockfd = accept(sock->sockfd, (struct sockaddr *) &clientaddr, &nSize);

    if(newsock->sockfd == SOCKET_ERROR) {
        RING_API_FREE(newsock);
        if(ring_vm_socket_wouldblock()) {
            return;
        }
        RING_API_ERROR("Accept Failed");
        return;
    }

    
    RING_API_RETCPOINTER(newsock, RING_VM_POINTER_SOCKET);
}

void ring_vm_socket_send(void *pPointer) {
    RING_SOCKET *sock;
    int flags = 0, sent;

    if(RING_API_PARACOUNT == 3) {
        if(!RING_API_ISNUMBER(3)) {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }
        flags = (int) RING_API_GETNUMBER(3);
    }
    else if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISSTRING(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);

    sent = send(sock->sockfd, RING_API_GETSTRING(2), RING_API_GETSTRINGSIZE(2), flags);

    if(sent == SOCKET_ERROR) {
        if(ring_vm_socket_wouldblock()) {
            RING_API_RETNUMBER(-2);
            return;
        }
        RING_API_ERROR("Send Failed");
        return;
    }

    RING_API_RETNUMBER(sent);
}

void ring_vm_socket_sendto(void *pPointer) {
    RING_SOCKET *sock;
    int flags = 0, sent;
    const char *host = NULL;
    int port = 0;
    struct addrinfo hints, *res = NULL;
    int have_dest = 0;

    if(RING_API_PARACOUNT == 2) {
        /* use stored sender from recvfrom / connect */
    }
    else if(RING_API_PARACOUNT == 3) {
        if(!RING_API_ISNUMBER(3)) {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }
        flags = (int) RING_API_GETNUMBER(3);
    }
    else if(RING_API_PARACOUNT == 4) {
        if(!(RING_API_ISSTRING(3) && RING_API_ISNUMBER(4))) {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }
        host = RING_API_GETSTRING(3);
        port = (int) RING_API_GETNUMBER(4);
        have_dest = 1;
    }
    else if(RING_API_PARACOUNT == 5) {
        if(!(RING_API_ISSTRING(3) && RING_API_ISNUMBER(4) && RING_API_ISNUMBER(5))) {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }
        host = RING_API_GETSTRING(3);
        port = (int) RING_API_GETNUMBER(4);
        flags = (int) RING_API_GETNUMBER(5);
        have_dest = 1;
    }
    else {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISSTRING(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);

    if(have_dest) {
        char cPort[6];
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_DGRAM;
        snprintf(cPort, 6, "%d", port);
        if(getaddrinfo(host, cPort, &hints, &res) != 0) {
            RING_API_ERROR("getaddrinfo Failed");
            return;
        }
        sent = sendto(sock->sockfd, RING_API_GETSTRING(2), RING_API_GETSTRINGSIZE(2), flags,
                      res->ai_addr, res->ai_addrlen);
        freeaddrinfo(res);
    }
    else {
        if(sock->fromlen == 0) {
            RING_API_ERROR("No destination address (call recvfrom first, connect, or pass host/port)");
            return;
        }
        sent = sendto(sock->sockfd, RING_API_GETSTRING(2), RING_API_GETSTRINGSIZE(2), flags,
                      (const struct sockaddr *) &sock->from, sock->fromlen);
    }

    if(sent == SOCKET_ERROR) {
        if(ring_vm_socket_wouldblock()) {
            RING_API_RETNUMBER(-2);
            return;
        }
        RING_API_ERROR("Sendto Failed");
        return;
    }

    RING_API_RETNUMBER(sent);
}

void ring_vm_socket_recv(void *pPointer) {
    RING_SOCKET *sock;
    char *msg;
    int nBytes, flags = 0;

    if(RING_API_PARACOUNT == 3) {
        if(!RING_API_ISNUMBER(3)) {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }
        flags = (int) RING_API_GETNUMBER(3);
    }
    else if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISNUMBER(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    if(!(msg = (char *) RING_API_MALLOC(RING_API_GETNUMBER(2))))
    {
        RING_API_ERROR(RING_OOM);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);
    nBytes = recv(sock->sockfd, msg, RING_API_GETNUMBER(2), flags);

    if(nBytes == SOCKET_ERROR) {
        int wouldblock = ring_vm_socket_wouldblock();
        RING_API_FREE(msg);
        if(wouldblock) {
            return;
        }
        RING_API_ERROR("Recv Failed");
        return;
    }

    RING_API_RETSTRING2(msg, nBytes);
    RING_API_FREE(msg);
}

void ring_vm_socket_recvfrom(void *pPointer) {
    RING_SOCKET *sock;
    char *msg;
    int nBytes, flags = 0;

    if(RING_API_PARACOUNT == 3) {
        if(!RING_API_ISNUMBER(3)) {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }
        flags = (int) RING_API_GETNUMBER(3);
    }
    else if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISNUMBER(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    if(!(msg = (char *) RING_API_MALLOC(RING_API_GETNUMBER(2))))
    {
        RING_API_ERROR(RING_OOM);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);
    sock->fromlen = sizeof(sock->from);
    nBytes = recvfrom(sock->sockfd, msg, RING_API_GETNUMBER(2), flags,
                      (struct sockaddr *) &sock->from, &sock->fromlen);
    
    if(nBytes == SOCKET_ERROR) {
        int wouldblock = ring_vm_socket_wouldblock();
        RING_API_FREE(msg);
        if(wouldblock) {
            return;
        }
        RING_API_ERROR("Recvfrom Failed");
        return;
    }

    RING_API_RETSTRING2(msg, nBytes);
    RING_API_FREE(msg);
}

void ring_vm_socket_connect(void *pPointer) {
    RING_SOCKET *sock;
    char cPort[6];
    int n;

    if(RING_API_PARACOUNT != 3) {
        RING_API_ERROR(RING_API_MISS3PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISNUMBER(3))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);

    snprintf(cPort, 6, "%d", (int) RING_API_GETNUMBER(3));
    
    if(getaddrinfo(RING_API_GETSTRING(2), cPort, &sock->hints, &sock->addr) != 0) {
        RING_API_ERROR("Invalid address");
        return;
    }

    if((n = connect(sock->sockfd, sock->addr->ai_addr, sock->addr->ai_addrlen)) == SOCKET_ERROR) {
        RING_API_ERROR("Connection Refused");
        return;
    }

    RING_API_RETNUMBER(n);
}

void ring_vm_socket_close(void *pPointer) {
    RING_SOCKET *sock;

    if (RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);
    CLOSESOCKET(sock->sockfd);
    
    if(sock->addr)
    {
        freeaddrinfo(sock->addr);
    }

    RING_API_FREE(sock);
    RING_API_SETNULLPOINTER(1);
}

void ring_vm_socket_gethostbyname(void *pPointer) {
    struct hostent *host_entry;

#ifdef _WIN32
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup failed");
        return;
    }
#endif

    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISSTRING(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    if ((host_entry = gethostbyname((const char *) RING_API_GETSTRING(1))) == NULL) {
        RING_API_ERROR("Host Not Valid");
        return;
    }


    RING_API_RETSTRING(inet_ntoa(*((struct in_addr *) host_entry->h_addr_list[0])));
}

void ring_vm_socket_gethostbyaddr(void *pPointer) {
    List *ringval,*names;
    char **temp;
    struct hostent *host_entry;
    struct addrinfo hints, *addr;
    void *addr2;
    int nSize;

#ifdef _WIN32
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup failed");
        return;
    }
#endif

    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISSTRING(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = 0;
    hints.ai_flags = AI_PASSIVE;

    if(getaddrinfo(RING_API_GETSTRING(1), "0", &hints, &addr) != 0)
    {
        RING_API_ERROR("getaddrinfo failed");
        return;
    }
    
    switch (addr->ai_family)
    {
    case AF_INET:
        nSize = sizeof(struct in_addr);
        addr2 = (struct in_addr *) RING_API_MALLOC(nSize);
        break;

    case AF_INET6:
        nSize = sizeof(struct in6_addr);
        addr2 = (struct in6_addr *) RING_API_MALLOC(nSize);
        break;
    
    default:
        freeaddrinfo(addr);
        RING_API_ERROR("Invalid Addr Family");
        return;
    }

    /* Check if allocation failed */
    if(!addr2)
    {
        freeaddrinfo(addr);
        RING_API_ERROR(RING_OOM);
        return;
    }
    
    inet_pton(addr->ai_family, RING_API_GETSTRING(1), addr2);
    
    if ((host_entry = gethostbyaddr((const char*) addr2, nSize, addr->ai_family)) == NULL) {
        RING_API_FREE(addr2);
        freeaddrinfo(addr);
        RING_API_ERROR("Host Not Valid");
        return;
    }

    RING_API_FREE(addr2);
    freeaddrinfo(addr);

    ringval = RING_API_NEWLIST;
    ring_list_addstring(ringval, host_entry->h_name);
    names = ring_list_newlist(ringval);
    
    if(host_entry->h_aliases != NULL) {
        for(temp = host_entry->h_aliases; *temp; temp++) {
            ring_list_addstring(names, *temp);
        }
    }
    
    ring_list_addint(ringval, host_entry->h_addrtype);

#ifdef h_addr
    for(temp = host_entry->h_addr_list; *temp; temp++) {
        ring_list_addstring(ringval, inet_ntoa(*((struct in_addr *) temp)));
    }
#else
    ring_list_addstring(ringval, inet_ntoa(*((struct in_addr *) host_entry->h_addr)));
#endif

    RING_API_RETLIST(ringval);
}

void ring_vm_socket_gethostname(void *pPointer) {
    int len = 1024;
    char *hostname;

#ifdef _WIN32
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup Failed");
        return;
    }
#endif

    if(!(hostname = (char *) RING_API_MALLOC(len)))
    {
        RING_API_ERROR(RING_OOM);
        return;
    }

    if(gethostname(hostname, len) != 0) {
        RING_API_ERROR("Get Hostname Failed");
        return;
    }

    RING_API_RETSTRING(hostname);
    RING_API_FREE(hostname);

}

void ring_vm_socket_getservbyname(void *pPointer) {

    char *servName;
    struct servent *s;
    char *proto = "tcp";

#ifdef _WIN32
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup Failed");
        return;
    }
#endif

    if(RING_API_PARACOUNT < 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISSTRING(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    if(RING_API_PARACOUNT == 2) {
        if(RING_API_ISSTRING(2)) 
            proto = RING_API_GETSTRING(2);
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }
    }

    servName = RING_API_GETSTRING(1);

    if((s = getservbyname(servName, proto)) != NULL) {
        RING_API_RETNUMBER(ntohs(s->s_port));
    }

    else {
        RING_API_ERROR("getservbyname Failed");
        return;
    }
}

void ring_vm_socket_getservbyport(void *pPointer) {

    int port;
    struct servent *s;
    char *proto = "tcp";

#ifdef _WIN32
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup Failed");
        return;
    }

#endif

    if(RING_API_PARACOUNT < 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISNUMBER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    if(RING_API_PARACOUNT == 2) {
        if(RING_API_ISSTRING(2)) 
            proto = RING_API_GETSTRING(2);
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }
    }

    port = RING_API_GETNUMBER(1);

    if((s = getservbyport(htons(port), proto)) != NULL) {
        RING_API_RETSTRING(s->s_name);
    }

    else {
        RING_API_ERROR("getservbyport Failed");
        return;
    }
}

void ring_vm_socket_ntohl(void *pPointer) {
    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISNUMBER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_API_RETNUMBER((int) ntohl(RING_API_GETNUMBER(1)));
}

void ring_vm_socket_ntohs(void *pPointer) {
    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISNUMBER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_API_RETNUMBER((int) ntohs(RING_API_GETNUMBER(1)));
}

void ring_vm_socket_htonl(void *pPointer) {
    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISNUMBER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_API_RETNUMBER((int) htonl(RING_API_GETNUMBER(1)));
}

void ring_vm_socket_htons(void *pPointer) {
    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISNUMBER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_API_RETNUMBER((int) htons(RING_API_GETNUMBER(1)));
}

void ring_vm_socket_inet_addr(void *pPointer) {

    const char *ip;
    uint32_t address;

#ifdef _WIN32
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup Failed");
        return;
    }
#endif

    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISSTRING(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    ip = RING_API_GETSTRING(1);

    if(strcmp(ip, "255.255.255.255") == 0) 
        address = INADDR_BROADCAST; 
    
    else {
        address = inet_addr(ip);
        if(address == INADDR_NONE) {
            RING_API_ERROR("IP Address is not valid");
            return;
        }

    }

    RING_API_RETSTRING2((char *) &address, sizeof(address));    
}

void ring_vm_socket_inet_ntoa(void *pPointer) {

#ifdef _WIN32
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup failed");
        return;
    }
#endif

    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISSTRING(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_API_RETSTRING(inet_ntoa(*((struct in_addr *) RING_API_GETSTRING(1))));
}

void ring_vm_socket_inet_pton(void *pPointer) {

    int nDomain, nSize, n;
    unsigned char *pBuffer;

#ifdef _WIN32
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup failed");
        return;
    }
#endif

    if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!RING_API_ISNUMBER(1) && !RING_API_ISSTRING(2)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    nDomain = RING_API_GETNUMBER(1);

    switch (nDomain)
    {
    case AF_INET:
        nSize = sizeof(struct in_addr);
        pBuffer = (unsigned char *) RING_API_MALLOC(nSize);
        break;

    case AF_INET6:
        nSize = sizeof(struct in6_addr);
        pBuffer = (unsigned char *) RING_API_MALLOC(nSize);
        break;
    
    default:
        RING_API_ERROR("Invalid Addr Family");
        return;
    }

    /* Check if allocation failed */
    if(!pBuffer)
    {
        RING_API_ERROR(RING_OOM);
        return;
    }
    
    if((n = inet_pton(nDomain, RING_API_GETSTRING(2), pBuffer)) == 0) {
        RING_API_ERROR("Invalid IP Addr");
        return;
    }

    else if(n < 0) {
        RING_API_ERROR("inet_pton Error");
        return;
    }

    RING_API_RETSTRING2((char *) pBuffer, nSize);
    RING_API_FREE(pBuffer);
}

void ring_vm_socket_inet_ntop(void *pPointer) {
    int nDomain, nSize;
    char *pAddr;

#ifdef _WIN32
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup failed");
        return;
    }
#endif

    if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!RING_API_ISNUMBER(1) && !RING_API_ISSTRING(2)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    nDomain = RING_API_GETNUMBER(1);

    switch (nDomain)
    {
    case AF_INET:
        nSize = INET_ADDRSTRLEN;
        pAddr = (char *) RING_API_MALLOC(nSize);
        break;

    case AF_INET6:
        nSize = INET6_ADDRSTRLEN;
        pAddr = (char *) RING_API_MALLOC(nSize);
        break;
    
    default:
        RING_API_ERROR("Invalid Addr Family");
        return;
    }

    /* Check if allocation failed */
    if(!pAddr)
    {
        RING_API_ERROR(RING_OOM);
        return;
    }

    if(inet_ntop(nDomain, RING_API_GETSTRING(2), pAddr, nSize) == NULL) {
        RING_API_ERROR("inet_ntop Error");
        return;
    }

    RING_API_RETSTRING(pAddr);
    RING_API_FREE(pAddr);
}


void ring_vm_socket_cleanup(void *pPointer) 
{

#ifdef _WIN32
    WSACleanup();
#endif

}

static int ring_vm_socket_wouldblock(void) {
#ifdef _WIN32
    return (WSAGetLastError() == WSAEWOULDBLOCK);
#else
    int e = errno;
    return (e == EAGAIN || e == EWOULDBLOCK);
#endif
}

static List *ring_vm_socket_make_addr_list(void *pPointer, struct sockaddr *sa, socklen_t len) {
    List *pList = RING_API_NEWLIST;
    char buf[INET6_ADDRSTRLEN];
    int port = 0;

    buf[0] = '\0';

    if(sa->sa_family == AF_INET) {
        struct sockaddr_in *s = (struct sockaddr_in *) sa;
        inet_ntop(AF_INET, &s->sin_addr, buf, sizeof(buf));
        port = ntohs(s->sin_port);
    }
    else if(sa->sa_family == AF_INET6) {
        struct sockaddr_in6 *s = (struct sockaddr_in6 *) sa;
        inet_ntop(AF_INET6, &s->sin6_addr, buf, sizeof(buf));
        port = ntohs(s->sin6_port);
    }

    ring_list_addstring(pList, buf);
    ring_list_addint(pList, port);
    return pList;
}

static int ring_vm_socket_add_fdset(List *lst, fd_set *set, int maxfd) {
    int i, n;

    if(!lst) return maxfd;
    n = (int) ring_list_getsize(lst);

    for(i = 1; i <= n; i++) {
        List *item = ring_list_getlist(lst, i);
        RING_SOCKET *s;
        if(!item) continue;
        s = (RING_SOCKET *) ring_list_getpointer(item, RING_CPOINTER_POINTER);
        if(!s) continue;
#ifdef _WIN32
        if(set->fd_count >= FD_SETSIZE) return -1;
#else
        /* POSIX: fd_set is a bitmap; fd >= FD_SETSIZE would write out of bounds. */
        if(s->sockfd >= (SOCKET_T) FD_SETSIZE) return -1;
#endif
        FD_SET(s->sockfd, set);
#ifndef _WIN32
        if((int) s->sockfd > maxfd) maxfd = (int) s->sockfd;
#endif
    }

    return maxfd;
}

static void ring_vm_socket_collect_fdset(List *src, fd_set *set, List *dst) {
    int i, n;

    if(!src) return;
    n = (int) ring_list_getsize(src);

    for(i = 1; i <= n; i++) {
        List *item = ring_list_getlist(src, i);
        RING_SOCKET *s;
        if(!item) continue;
        s = (RING_SOCKET *) ring_list_getpointer(item, RING_CPOINTER_POINTER);
        if(!s) continue;
        if(FD_ISSET(s->sockfd, set)) {
            ring_list_addcpointer(dst, s, RING_VM_POINTER_SOCKET);
        }
    }
}

void ring_vm_socket_shutdown(void *pPointer) {
    RING_SOCKET *sock;
    int how;

    if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISNUMBER(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);
    how = (int) RING_API_GETNUMBER(2);

    if(shutdown(sock->sockfd, how) == SOCKET_ERROR) {
        RING_API_ERROR("Shutdown Failed");
        return;
    }
}

void ring_vm_socket_setnonblocking(void *pPointer) {
    RING_SOCKET *sock;
    int flag;

    if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISNUMBER(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);
    flag = (int) RING_API_GETNUMBER(2);

#ifdef _WIN32
    {
        u_long mode = flag ? 1 : 0;
        if(ioctlsocket(sock->sockfd, FIONBIO, &mode) == SOCKET_ERROR) {
            RING_API_ERROR("SetNonBlocking Failed");
            return;
        }
    }
#else
    {
        int flags = fcntl(sock->sockfd, F_GETFL, 0);
        if(flag) flags |= O_NONBLOCK;
        else flags &= ~O_NONBLOCK;
        if(fcntl(sock->sockfd, F_SETFL, flags) == -1) {
            RING_API_ERROR("SetNonBlocking Failed");
            return;
        }
    }
#endif
}

void ring_vm_socket_select(void *pPointer) {
    fd_set rfds, wfds, efds;
    struct timeval tv, *ptv = NULL;
    int maxfd = 0, rc;
    List *pin_r, *pin_w, *pin_e, *pout, *pout_r, *pout_w, *pout_e;

    if(RING_API_PARACOUNT < 3 || RING_API_PARACOUNT > 4) {
        RING_API_ERROR(RING_API_MISS3PARA);
        return;
    }

    if(!(RING_API_ISLIST(1) && RING_API_ISLIST(2) && RING_API_ISLIST(3)) ||
       (RING_API_PARACOUNT == 4 && !RING_API_ISNUMBER(4))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    pin_r = RING_API_GETLIST(1);
    pin_w = RING_API_GETLIST(2);
    pin_e = RING_API_GETLIST(3);

    FD_ZERO(&rfds);
    FD_ZERO(&wfds);
    FD_ZERO(&efds);

    if((maxfd = ring_vm_socket_add_fdset(pin_r, &rfds, maxfd)) < 0 ||
       (maxfd = ring_vm_socket_add_fdset(pin_w, &wfds, maxfd)) < 0 ||
       (maxfd = ring_vm_socket_add_fdset(pin_e, &efds, maxfd)) < 0) {
        RING_API_ERROR("select: FD_SETSIZE limit exceeded");
        return;
    }

    if(RING_API_PARACOUNT == 4) {
        double t = RING_API_GETNUMBER(4);
        if(t >= 0) {
            tv.tv_sec = (long) t;
            tv.tv_usec = (long) ((t - tv.tv_sec) * 1000000);
            ptv = &tv;
        }
    }

    rc = select(maxfd + 1, &rfds, &wfds, &efds, ptv);

    if(rc == SOCKET_ERROR) {
        RING_API_ERROR("Select Failed");
        return;
    }

    pout = RING_API_NEWLIST;
    pout_r = ring_list_newlist(pout);
    pout_w = ring_list_newlist(pout);
    pout_e = ring_list_newlist(pout);

    ring_vm_socket_collect_fdset(pin_r, &rfds, pout_r);
    ring_vm_socket_collect_fdset(pin_w, &wfds, pout_w);
    ring_vm_socket_collect_fdset(pin_e, &efds, pout_e);

    RING_API_RETLIST(pout);
}

void ring_vm_socket_lasterror(void *pPointer) {
#ifdef _WIN32
    RING_API_RETNUMBER(WSAGetLastError());
#else
    RING_API_RETNUMBER(errno);
#endif
}

void ring_vm_socket_getaddrinfo(void *pPointer) {
    struct addrinfo hints, *res, *rp;
    List *pList, *pEntry, *pAddr;
    const char *host, *service;
    int family = AF_UNSPEC;

    if(RING_API_PARACOUNT < 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!(RING_API_ISSTRING(1) && RING_API_ISSTRING(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    host = RING_API_GETSTRING(1);
    service = RING_API_GETSTRING(2);

    if(RING_API_PARACOUNT >= 3 && RING_API_ISNUMBER(3)) {
        family = (int) RING_API_GETNUMBER(3);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = family;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if(getaddrinfo(host, service, &hints, &res) != 0) {
        RING_API_ERROR("getaddrinfo Failed");
        return;
    }

    pList = RING_API_NEWLIST;

    for(rp = res; rp != NULL; rp = rp->ai_next) {
        pEntry = ring_list_newlist(pList);
        ring_list_addint(pEntry, rp->ai_family);
        ring_list_addint(pEntry, rp->ai_socktype);
        ring_list_addint(pEntry, rp->ai_protocol);
        pAddr = ring_vm_socket_make_addr_list(pPointer, rp->ai_addr, rp->ai_addrlen);
        ring_list_addstring(pEntry, ring_list_getstring(pAddr, 1));
        ring_list_addint(pEntry, ring_list_getint(pAddr, 2));
    }

    freeaddrinfo(res);
    RING_API_RETLIST(pList);
}

void ring_vm_socket_getsockname(void *pPointer) {
    RING_SOCKET *sock;
    struct sockaddr_storage addr;
    socklen_t len = sizeof(addr);
    List *pList;

    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);

    if(getsockname(sock->sockfd, (struct sockaddr *) &addr, &len) == SOCKET_ERROR) {
        RING_API_ERROR("Getsockname Failed");
        return;
    }

    pList = ring_vm_socket_make_addr_list(pPointer, (struct sockaddr *) &addr, len);
    RING_API_RETLIST(pList);
}

void ring_vm_socket_getpeername(void *pPointer) {
    RING_SOCKET *sock;
    struct sockaddr_storage addr;
    socklen_t len = sizeof(addr);
    List *pList;

    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock = (RING_SOCKET *) RING_API_GETCPOINTER(1, RING_VM_POINTER_SOCKET);

    if(getpeername(sock->sockfd, (struct sockaddr *) &addr, &len) == SOCKET_ERROR) {
        RING_API_ERROR("Getpeername Failed");
        return;
    }

    pList = ring_vm_socket_make_addr_list(pPointer, (struct sockaddr *) &addr, len);
    RING_API_RETLIST(pList);
}

void ring_vm_socket_socketpair(void *pPointer) {
    RING_SOCKET *a, *b;
    SOCKET_T fd0, fd1;
    int family = AF_UNIX, type = SOCK_STREAM, proto = 0;

    if(RING_API_PARACOUNT >= 3) {
        if(!(RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2) && RING_API_ISNUMBER(3))) {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }
        family = (int) RING_API_GETNUMBER(1);
        type = (int) RING_API_GETNUMBER(2);
        proto = (int) RING_API_GETNUMBER(3);
    }

#ifdef _WIN32
    {
        SOCKET_T listener;
        struct sockaddr_in addr;
        int addrlen = (int) sizeof(addr);

        (void) family; (void) type; (void) proto;

        listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(listener == INVALID_SOCKET) {
            RING_API_ERROR("Socketpair Failed");
            return;
        }

        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        addr.sin_port = 0;

        if(bind(listener, (struct sockaddr *) &addr, sizeof(addr)) == SOCKET_ERROR ||
           listen(listener, 1) == SOCKET_ERROR ||
           getsockname(listener, (struct sockaddr *) &addr, &addrlen) == SOCKET_ERROR) {
            CLOSESOCKET(listener);
            RING_API_ERROR("Socketpair Failed");
            return;
        }

        fd0 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(fd0 == INVALID_SOCKET ||
           connect(fd0, (struct sockaddr *) &addr, sizeof(addr)) == SOCKET_ERROR) {
            if(fd0 != INVALID_SOCKET) CLOSESOCKET(fd0);
            CLOSESOCKET(listener);
            RING_API_ERROR("Socketpair Failed");
            return;
        }

        fd1 = accept(listener, NULL, NULL);
        CLOSESOCKET(listener);
        if(fd1 == INVALID_SOCKET) {
            CLOSESOCKET(fd0);
            RING_API_ERROR("Socketpair Failed");
            return;
        }
    }
#else
    {
        int fds[2];

        if(socketpair(family, type, proto, fds) == -1) {
            RING_API_ERROR("Socketpair Failed");
            return;
        }
        fd0 = (SOCKET_T) fds[0];
        fd1 = (SOCKET_T) fds[1];
    }
#endif

    if(!(a = (RING_SOCKET *) RING_API_MALLOC(sizeof(RING_SOCKET)))) {
        CLOSESOCKET(fd0); CLOSESOCKET(fd1);
        RING_API_ERROR(RING_OOM);
        return;
    }

    if(!(b = (RING_SOCKET *) RING_API_MALLOC(sizeof(RING_SOCKET)))) {
        RING_API_FREE(a);
        CLOSESOCKET(fd0); CLOSESOCKET(fd1);
        RING_API_ERROR(RING_OOM);
        return;
    }

    a->addr = NULL;
    memset(&a->from, 0, sizeof(a->from));
    a->fromlen = 0;
    memset(&a->hints, 0, sizeof(a->hints));
    a->sockfd = fd0;

    b->addr = NULL;
    memset(&b->from, 0, sizeof(b->from));
    b->fromlen = 0;
    memset(&b->hints, 0, sizeof(b->hints));
    b->sockfd = fd1;

    {
        List *pList = RING_API_NEWLIST;
        ring_list_addcpointer(pList, a, RING_VM_POINTER_SOCKET);
        ring_list_addcpointer(pList, b, RING_VM_POINTER_SOCKET);
        RING_API_RETLIST(pList);
    }
}

void ring_vm_socket_getprotobyname(void *pPointer) {
    struct protoent *p;

    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISSTRING(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    p = getprotobyname(RING_API_GETSTRING(1));

    if(p == NULL) {
        RING_API_ERROR("getprotobyname Failed");
        return;
    }

    RING_API_RETNUMBER(p->p_proto);
}


RING_API void ringlib_init(RingState *pRingState) {
    RING_API_REGISTER("socket",ring_vm_socket_init);
    RING_API_REGISTER("socketfd",ring_vm_socket_fd);
    RING_API_REGISTER("shutdownsocket",ring_vm_socket_shutdown);
    RING_API_REGISTER("setnonblocking",ring_vm_socket_setnonblocking);
    RING_API_REGISTER("select",ring_vm_socket_select);
    RING_API_REGISTER("socklasterror",ring_vm_socket_lasterror);
    RING_API_REGISTER("getaddrinfo",ring_vm_socket_getaddrinfo);
    RING_API_REGISTER("getsockname",ring_vm_socket_getsockname);
    RING_API_REGISTER("getpeername",ring_vm_socket_getpeername);
    RING_API_REGISTER("socketpair",ring_vm_socket_socketpair);
    RING_API_REGISTER("getprotobyname",ring_vm_socket_getprotobyname);
    RING_API_REGISTER("setsockopt",ring_vm_socket_setsockopt);
    RING_API_REGISTER("getsockopt",ring_vm_socket_getsockopt);
    RING_API_REGISTER("bind",ring_vm_socket_bind);
    RING_API_REGISTER("listen",ring_vm_socket_listen);
    RING_API_REGISTER("accept",ring_vm_socket_accept);
    RING_API_REGISTER("send",ring_vm_socket_send);
    RING_API_REGISTER("sendto",ring_vm_socket_sendto);
    RING_API_REGISTER("recv",ring_vm_socket_recv);
    RING_API_REGISTER("recvfrom",ring_vm_socket_recvfrom);
    RING_API_REGISTER("connect",ring_vm_socket_connect);
    RING_API_REGISTER("close",ring_vm_socket_close);
    RING_API_REGISTER("gethostbyname",ring_vm_socket_gethostbyname);
    RING_API_REGISTER("gethostbyaddr",ring_vm_socket_gethostbyaddr);
    RING_API_REGISTER("gethostname",ring_vm_socket_gethostname);
    RING_API_REGISTER("getservbyname",ring_vm_socket_getservbyname);
    RING_API_REGISTER("getservbyport",ring_vm_socket_getservbyport);
    RING_API_REGISTER("ntohs",ring_vm_socket_ntohs);
    RING_API_REGISTER("ntohl",ring_vm_socket_ntohl);
    RING_API_REGISTER("htonl",ring_vm_socket_htonl);
    RING_API_REGISTER("htons",ring_vm_socket_htons);
    RING_API_REGISTER("inet_addr",ring_vm_socket_inet_addr);
    RING_API_REGISTER("inet_ntoa",ring_vm_socket_inet_ntoa); 
    RING_API_REGISTER("inet_pton",ring_vm_socket_inet_pton);
    RING_API_REGISTER("inet_ntop",ring_vm_socket_inet_ntop);


    /* Constants */

    RING_API_REGISTER("get_pf_unspec",ring_vm_socket_constant_pf_unspec);
    RING_API_REGISTER("get_pf_unix",ring_vm_socket_constant_pf_unix);
    RING_API_REGISTER("get_pf_inet",ring_vm_socket_constant_pf_inet);
    RING_API_REGISTER("get_pf_inet6",ring_vm_socket_constant_pf_inet6);

    RING_API_REGISTER("get_af_unspec",ring_vm_socket_constant_af_unspec);
    RING_API_REGISTER("get_af_unix",ring_vm_socket_constant_af_unix);
    RING_API_REGISTER("get_af_inet",ring_vm_socket_constant_af_inet);
    RING_API_REGISTER("get_af_inet6",ring_vm_socket_constant_af_inet6);

    RING_API_REGISTER("get_sock_stream",ring_vm_socket_constant_sock_stream);
    RING_API_REGISTER("get_sock_dgram",ring_vm_socket_constant_sock_dgram);
    RING_API_REGISTER("get_sock_raw",ring_vm_socket_constant_sock_raw);
    RING_API_REGISTER("get_sock_rdm",ring_vm_socket_constant_sock_rdm);
    RING_API_REGISTER("get_sock_seqpacket",ring_vm_socket_constant_sock_seqpacket);

    RING_API_REGISTER("get_ipproto_ip",ring_vm_socket_constant_ipproto_ip);
    RING_API_REGISTER("get_ipproto_tcp",ring_vm_socket_constant_ipproto_tcp);
    RING_API_REGISTER("get_ipproto_udp",ring_vm_socket_constant_ipproto_udp);
    RING_API_REGISTER("get_sol_socket",ring_vm_socket_constant_sol_socket);

    RING_API_REGISTER("get_so_debug",ring_vm_socket_constant_so_debug);
    RING_API_REGISTER("get_ip_add_membership",ring_vm_socket_constant_ip_add_membership);
    RING_API_REGISTER("get_ip_add_source_membership",ring_vm_socket_constant_ip_add_source_membership);
    RING_API_REGISTER("get_ip_block_source",ring_vm_socket_constant_ip_block_source);
    RING_API_REGISTER("get_ip_drop_membership",ring_vm_socket_constant_ip_drop_membership);
    RING_API_REGISTER("get_ip_drop_source_membership",ring_vm_socket_constant_ip_drop_source_membership);
    RING_API_REGISTER("get_ip_hdrincl",ring_vm_socket_constant_ip_hdrincl);
/*
    RING_API_REGISTER("get_ip_mtu",ring_vm_socket_constant_ip_mtu);
    RING_API_REGISTER("get_ip_mtu_discover",ring_vm_socket_constant_ip_mtu_discover);
*/
    RING_API_REGISTER("get_ip_multicast_loop",ring_vm_socket_constant_ip_multicast_loop);
    RING_API_REGISTER("get_ip_multicast_ttl",ring_vm_socket_constant_ip_multicast_ttl);
    RING_API_REGISTER("get_ip_options",ring_vm_socket_constant_ip_options);
/*
    RING_API_REGISTER("get_ip_pktinfo",ring_vm_socket_constant_ip_pktinfo);
*/
    RING_API_REGISTER("get_ip_recvtos",ring_vm_socket_constant_ip_recvtos);
    RING_API_REGISTER("get_ip_recvttl",ring_vm_socket_constant_ip_recvttl);
    RING_API_REGISTER("get_ip_tos",ring_vm_socket_constant_ip_tos);
    RING_API_REGISTER("get_ip_ttl",ring_vm_socket_constant_ip_ttl);
    RING_API_REGISTER("get_ip_unblock_source",ring_vm_socket_constant_ip_unblock_source);
/*
    RING_API_REGISTER("get_ip_unicast_if",ring_vm_socket_constant_ip_unicast_if);
*/
    RING_API_REGISTER("get_so_acceptconn",ring_vm_socket_constant_so_acceptconn);
    RING_API_REGISTER("get_so_broadcast",ring_vm_socket_constant_so_broadcast);
    RING_API_REGISTER("get_so_dontroute",ring_vm_socket_constant_so_dontroute);
    RING_API_REGISTER("get_so_error",ring_vm_socket_constant_so_error);
    RING_API_REGISTER("get_so_keepalive",ring_vm_socket_constant_so_keepalive);
    RING_API_REGISTER("get_so_linger",ring_vm_socket_constant_so_linger);
    RING_API_REGISTER("get_so_oobinline",ring_vm_socket_constant_so_oobinline);
    RING_API_REGISTER("get_so_rcvbuf",ring_vm_socket_constant_so_rcvbuf);
    RING_API_REGISTER("get_so_reuseaddr",ring_vm_socket_constant_so_reuseaddr);
    RING_API_REGISTER("get_so_sndbuf",ring_vm_socket_constant_so_sndbuf);
    RING_API_REGISTER("get_so_type",ring_vm_socket_constant_so_type);
    RING_API_REGISTER("get_so_rcvlowat",ring_vm_socket_constant_so_rcvlowat);
    RING_API_REGISTER("get_so_sndlowat",ring_vm_socket_constant_so_sndlowat);
    RING_API_REGISTER("get_so_rcvtimeo",ring_vm_socket_constant_so_rcvtimeo);

    /* Additional socket options */
    RING_API_REGISTER("get_so_sndtimeo",ring_vm_socket_constant_so_sndtimeo);
    RING_API_REGISTER("get_so_exclusiveaddruse",ring_vm_socket_constant_so_exclusiveaddruse);
    RING_API_REGISTER("get_so_nosigpipe",ring_vm_socket_constant_so_nosigpipe);
    RING_API_REGISTER("get_so_reuseport",ring_vm_socket_constant_so_reuseport);

    /* Shutdown flags */
    RING_API_REGISTER("get_shut_rd",ring_vm_socket_constant_shut_rd);
    RING_API_REGISTER("get_shut_wr",ring_vm_socket_constant_shut_wr);
    RING_API_REGISTER("get_shut_rdwr",ring_vm_socket_constant_shut_rdwr);

    /* Would-block error code */
    RING_API_REGISTER("get_sock_ewouldblock",ring_vm_socket_constant_sock_ewouldblock);

    /* Protocols */
    RING_API_REGISTER("get_ipproto_raw",ring_vm_socket_constant_ipproto_raw);
    RING_API_REGISTER("get_ipproto_icmp",ring_vm_socket_constant_ipproto_icmp);
    RING_API_REGISTER("get_ipproto_igmp",ring_vm_socket_constant_ipproto_igmp);
    RING_API_REGISTER("get_ipproto_sctp",ring_vm_socket_constant_ipproto_sctp);

    /* TCP socket options */
    RING_API_REGISTER("get_tcp_nodelay",ring_vm_socket_constant_tcp_nodelay);
    RING_API_REGISTER("get_tcp_keepidle",ring_vm_socket_constant_tcp_keepidle);
    RING_API_REGISTER("get_tcp_keepintvl",ring_vm_socket_constant_tcp_keepintvl);
    RING_API_REGISTER("get_tcp_keepcnt",ring_vm_socket_constant_tcp_keepcnt);

    /* Message flags */
    RING_API_REGISTER("get_msg_oob",ring_vm_socket_constant_msg_oob);
    RING_API_REGISTER("get_msg_peek",ring_vm_socket_constant_msg_peek);
    RING_API_REGISTER("get_msg_waitall",ring_vm_socket_constant_msg_waitall);
    RING_API_REGISTER("get_msg_dontwait",ring_vm_socket_constant_msg_dontwait);

    RING_API_REGISTER("socketscleanup",ring_vm_socket_cleanup);
	
#ifdef _WIN32
	{
		/* initialize Winsock */
		WSADATA data;
		if (WSAStartup(MAKEWORD(2, 2), &data) == 0) {
			g_bWinsockInitialized = TRUE;
		}
		else {
			g_bWinsockInitialized = FALSE;
		}
	}
#endif

}

