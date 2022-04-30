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

#if defined _WIN32
	#define WIN32_LEAN_AND_MEAN
#endif

#include "sockets.h"

#ifdef win
BOOL g_bWinsockInitialized = FALSE;
#endif

void ring_vm_socket_init(void *pPointer) {

    if(RING_API_PARACOUNT < 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    } 

    if(!(RING_API_ISNUMBER(1) && RING_API_ISNUMBER(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    int proto = 0;

    if(RING_API_PARACOUNT == 3) {
        if(!RING_API_ISNUMBER(3)) {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }

        proto = (int) RING_API_GETNUMBER(3);
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_MALLOC(sizeof(RING_SOCKET));

#ifdef win
    sock->addr = NULL;
	if (!g_bWinsockInitialized) {
		RING_API_FREE(sock);
		RING_API_ERROR("WSAStartup Failed");
		return;
	}

	ZeroMemory(&sock->hints, sizeof(sock->hints));
    sock->sockfd = INVALID_SOCKET;
    sock->hints.ai_family = (int) RING_API_GETNUMBER(1);
    sock->hints.ai_socktype = (int) RING_API_GETNUMBER(2);
    sock->hints.ai_protocol = proto;
    sock->hints.ai_flags = AI_PASSIVE;

    if((sock->sockfd = socket(sock->hints.ai_family,sock->hints.ai_socktype,sock->hints.ai_protocol)) == INVALID_SOCKET) {
        RING_API_ERROR("Sock Init Failed");
		RING_API_FREE(sock);
        return;
    }


#else
    sock->addr.sin_family = RING_API_GETNUMBER(1);
    int type = RING_API_GETNUMBER(2), opt;

    if((sock->sockfd = socket(sock->addr.sin_family,type,proto)) == 0) {
        RING_API_ERROR("Sock Init Failed");
		RING_API_FREE(sock);
        return;
    }

#endif  
    
    RING_API_RETCPOINTER(sock,RING_VM_POINTER_SOCKET);
    
}

void ring_vm_socket_setsockopt(void *pPointer) {
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

    RING_SOCKET *sock;
    int level, optname, value;

#ifdef win
	if (!g_bWinsockInitialized) {
		RING_API_ERROR("WSAStartup failed");
		return;
	}
#endif

    sock = RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    level = RING_API_GETNUMBER(2);
    optname = RING_API_GETNUMBER(3);
    value = RING_API_GETNUMBER(4);

    if(setsockopt(sock->sockfd,level,optname,(const char *)&value,sizeof(value))) 
    {
        RING_API_ERROR("Set Socket Option Failed");
        return;
    }

}

void ring_vm_socket_getsockopt(void *pPointer) {
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

    RING_SOCKET *sock;
    int level, optname, valsize, buffer = 0;

#ifdef win
	if (!g_bWinsockInitialized) {
		RING_API_ERROR("WSAStartup failed");
		return;
	}
#endif

    sock = RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    level = RING_API_GETNUMBER(2);
    optname = RING_API_GETNUMBER(3);
    valsize = sizeof(buffer);

    if(getsockopt(sock->sockfd,level,optname,(char *)&buffer,&valsize)) 
    {
        RING_API_ERROR("Get Socket option Failed");
        return;
    }

    RING_API_RETNUMBER(buffer);
}

void ring_vm_socket_bind(void *pPointer) {
    if(RING_API_PARACOUNT != 3) {
        RING_API_ERROR(RING_API_MISS3PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISNUMBER(3))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    const char *host = RING_API_GETSTRING(2);
    const int port = (int) RING_API_GETNUMBER(3);

#ifdef win
    char sPort[10];
    if(getaddrinfo(NULL,itoa(port,sPort,10),&sock->hints,&sock->addr) != 0) {
        RING_API_ERROR("getaddrinfo Failed");
        return;
    }

    if(bind(sock->sockfd ,sock->addr->ai_addr,(int) sock->addr->ai_addrlen) == SOCKET_ERROR) {
        RING_API_ERROR("Bind Error");
        freeaddrinfo(sock->addr);
        return;
    }

#else
    sock->addr.sin_addr.s_addr = inet_addr(host);
    sock->addr.sin_port = htons(port);

    if(bind(sock->sockfd,(struct sockaddr *)&sock->addr,sizeof(sock->addr)) < 0) {
        RING_API_ERROR("Bind Error");
        return;
    }

#endif

}

void ring_vm_socket_listen(void *pPointer) {
 

    if(RING_API_PARACOUNT < 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    int n;
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

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);

#ifdef win
    if(listen(sock->sockfd,n) == SOCKET_ERROR) {
        RING_API_ERROR("Listen Failed");
        return;
    }

#else
    if(listen(sock->sockfd,n) < 0) {
        RING_API_ERROR("Listen Failed");
        return;
    }
#endif
    
}

void ring_vm_socket_accept(void *pPointer) {

    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    RING_SOCKET *newsockfd = (RING_SOCKET *) RING_API_MALLOC(sizeof(RING_SOCKET));
    
#ifdef win
    if((newsockfd->sockfd = accept(sock->sockfd,(struct sockaddr *) sock->addr,NULL)) == SOCKET_ERROR) {
        RING_API_ERROR("Accept Failed");
		RING_API_FREE(newsockfd);
        return;
    }

    
#else
    int addr_len = sizeof(sock->addr);
    if((newsockfd->sockfd = accept(sock->sockfd,(struct sockaddr *)&sock->addr,(socklen_t *)&addr_len)) < 0)
    {
        RING_API_ERROR("Accept Failed");
        return;
    }

#endif
    RING_API_RETCPOINTER(newsockfd,RING_VM_POINTER_SOCKET);
}

void ring_vm_socket_send(void *pPointer) {
    if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISSTRING(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    char *Msg = RING_API_GETSTRING(2);
    
    send(sock->sockfd,Msg,RING_API_GETSTRINGSIZE(2),0);
    
}

void ring_vm_socket_sendto(void *pPointer) {
    if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISSTRING(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    char *Msg = RING_API_GETSTRING(2);
    int addr_len = sizeof(sock->addr);
#ifdef win
    sendto(sock->sockfd,Msg,RING_API_GETSTRINGSIZE(2),0,(const struct sockaddr *) sock->addr,(socklen_t) addr_len);
#else
    sendto(sock->sockfd,Msg,RING_API_GETSTRINGSIZE(2),0,(const struct sockaddr *) &sock->addr,(socklen_t) addr_len);
#endif

}

void ring_vm_socket_recv(void *pPointer) {
    if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISNUMBER(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    size_t buffer = (size_t) RING_API_GETNUMBER(2);
    char *Msg = (char *) malloc(buffer);
    int bytes = recv(sock->sockfd,Msg,buffer,0);

    RING_API_RETSTRING2(Msg,bytes);
    free(Msg);
}

void ring_vm_socket_recvfrom(void *pPointer) {
    if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISNUMBER(2))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    size_t buffer = (size_t) RING_API_GETNUMBER(2);
    char *Msg = (char *) malloc(buffer);
    int addr_len = sizeof(sock->addr);
#ifdef win
    int bytes = (int) recvfrom(sock->sockfd,Msg,buffer,0,(struct sockaddr *) sock->addr,(socklen_t *)&addr_len);
#else
    int bytes = (int) recvfrom(sock->sockfd,Msg,buffer,0,(struct sockaddr *) &sock->addr,(socklen_t *)&addr_len);
#endif
    RING_API_RETSTRING2(Msg,bytes);
    free(Msg);
}

void ring_vm_socket_connect(void *pPointer) {
    if(RING_API_PARACOUNT != 3) {
        RING_API_ERROR(RING_API_MISS3PARA);
        return;
    }

    if(!(RING_API_ISCPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISNUMBER(3))) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    char *host = RING_API_GETSTRING(2);
    int port = (int) RING_API_GETNUMBER(3) , n;
    
#ifdef win
    char sPort[10];
    if(getaddrinfo(host,itoa(port,sPort,10),&sock->hints,&sock->addr) != 0) {
        RING_API_ERROR("Invalid address");
        return;
    }

    if((n = connect(sock->sockfd,sock->addr->ai_addr,(int) sock->addr->ai_addrlen)) == SOCKET_ERROR) {
        RING_API_ERROR("Connection Refused");
        return;
    }

#else
    sock->addr.sin_port = htons(port);

    if(inet_pton(sock->addr.sin_family,host,&sock->addr.sin_addr) <= 0) {
        RING_API_ERROR("Invalid address");
        return;
    }

    if((n = connect(sock->sockfd,(struct sockaddr *) &sock->addr,sizeof(sock->addr))) < 0) {
        RING_API_ERROR("Connection Refused");
        return;
    }

#endif

    RING_API_RETNUMBER(n);
}

void ring_vm_socket_close(void *pPointer) {
    if (RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);

#ifdef win
    closesocket(sock->sockfd);
#else
    close(sock->sockfd);
#endif
    RING_API_SETNULLPOINTER(1);
}

void ring_vm_socket_gethostbyname(void *pPointer) {
    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISSTRING(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    const char *host;
    struct hostent *host_entry;
    const char *ringval;

#ifdef win
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup failed");
        return;
    }

#endif
    host = RING_API_GETSTRING(1);
    if ((host_entry = gethostbyname(host)) == NULL) {
        RING_API_ERROR("Host Not Valid");
        return;
    }

    ringval = inet_ntoa(*((struct in_addr *) host_entry->h_addr_list[0]));

    RING_API_RETSTRING(ringval);
}

void ring_vm_socket_gethostbyaddr(void *pPointer) {
    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISSTRING(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }
    
    List *ringval,*names;
    const char *host;
    char **temp;
    struct hostent *host_entry;
    struct in_addr addr;

#ifdef win
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup failed");
        return;
    }
#endif

    host = RING_API_GETSTRING(1);
    addr.s_addr = inet_addr(host);
    if ((host_entry = gethostbyaddr((const char*)&addr,sizeof(addr),AF_INET)) == NULL) {
        RING_API_ERROR("Host Not Valid");
        return;
    }

    ringval = RING_API_NEWLIST;
    ring_list_addstring(ringval,host_entry->h_name);
    names = ring_list_newlist(ringval);
    
    if(host_entry->h_aliases != NULL) {
        for(temp = host_entry->h_aliases; *temp; temp++) {
            ring_list_addstring(names,*temp);
        }
    }
    
    ring_list_addint(ringval,host_entry->h_addrtype);
    
#ifdef win
    int i = 0;
    while(host_entry->h_addr_list[i] != 0) {
        ring_list_addstring(ringval,inet_ntoa(*((struct in_addr *) host_entry->h_addr_list[i++])));
    }

#else


#ifdef h_addr
    for(temp = host_entry->h_addr_list; *temp; temp++) {
        ring_list_addstring(ringval,inet_ntoa(*((struct in_addr *) temp)));
    }
#else
    ring_list_addstring(ringval,inet_ntoa(*((struct in_addr *) host_entry->h_addr)));
#endif

#endif

    RING_API_RETLIST(ringval);
}

void ring_vm_socket_gethostname(void *pPointer) {
    int len = 1024;
    char *hostname = (char *) malloc(len);

#ifdef win
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup Failed");
        return;
    }

#endif

    if(gethostname(hostname,len) != 0) {
        RING_API_ERROR("Get Hostname Failed");
        return;
    }

    RING_API_RETSTRING(hostname);
    free(hostname);

}

void ring_vm_socket_getservbyname(void *pPointer) {
    if(RING_API_PARACOUNT < 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISSTRING(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    char *servName = RING_API_GETSTRING(1);
    char *proto = "tcp";
    struct servent *s;

    if(RING_API_PARACOUNT == 2) {
        if(RING_API_ISSTRING(2)) 
            proto = RING_API_GETSTRING(2);
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }
    }

#ifdef win
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup Failed");
        return;
    }

#endif

    if(s = getservbyname(servName,proto)) {
        RING_API_RETNUMBER(ntohs(s->s_port));
    }

    else {
        RING_API_ERROR("getservbyname Failed");
        return;
    }
}

void ring_vm_socket_getservbyport(void *pPointer) {
    if(RING_API_PARACOUNT < 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISNUMBER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    int port = RING_API_GETNUMBER(1);
    char *proto = "tcp";
    struct servent *s;

    if(RING_API_PARACOUNT == 2) {
        if(RING_API_ISSTRING(2)) 
            proto = RING_API_GETSTRING(2);
        else {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }
    }

#ifdef win
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup Failed");
        return;
    }

#endif

    if(s = getservbyport(htons(port),proto)) {
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

    int n = (int) RING_API_GETNUMBER(1);
    RING_API_RETNUMBER((int) ntohl(n));
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

    int n = (int) RING_API_GETNUMBER(1);
    RING_API_RETNUMBER((int) ntohs(n));
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

    int n = (int) RING_API_GETNUMBER(1);
    RING_API_RETNUMBER((int) htonl(n));
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

    int n = (int) RING_API_GETNUMBER(1);
    RING_API_RETNUMBER((int) htons(n));
}

void ring_vm_socket_inet_addr(void *pPointer) {
    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISSTRING(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    const char *ip = RING_API_GETSTRING(1);
    unsigned long address;

#ifdef win
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup Failed");
        return;
    }
#endif
    if(strcmp(ip,"255.255.255.255") == 0) 
        address = INADDR_BROADCAST; 
    else {
        address = inet_addr(ip);
        if(address == INADDR_NONE) {
            RING_API_ERROR("IP Address is not valid");
            return;
        }

        RING_API_RETSTRING2((char *) &address,sizeof(address));
    }
    
}

void ring_vm_socket_inet_ntoa(void *pPointer) {
    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return;
    }

    if(!RING_API_ISSTRING(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    const char *address = RING_API_GETSTRING(1);

#ifdef win
    if(!g_bWinsockInitialized) {
        RING_API_ERROR("WSAStartup failed");
        return;
    }
#endif

    RING_API_RETSTRING(inet_ntoa(*((struct in_addr *) address)));
}


RING_API void ringlib_init(RingState *pRingState) {
    RING_API_REGISTER("socket",ring_vm_socket_init);
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
    RING_API_REGISTER("get_ip_mtu",ring_vm_socket_constant_ip_mtu);
    RING_API_REGISTER("get_ip_mtu_discover",ring_vm_socket_constant_ip_mtu_discover);
    RING_API_REGISTER("get_ip_multicast_loop",ring_vm_socket_constant_ip_multicast_loop);
    RING_API_REGISTER("get_ip_multicast_ttl",ring_vm_socket_constant_ip_multicast_ttl);
    RING_API_REGISTER("get_ip_options",ring_vm_socket_constant_ip_options);
    RING_API_REGISTER("get_ip_pktinfo",ring_vm_socket_constant_ip_pktinfo);
    RING_API_REGISTER("get_ip_recvtos",ring_vm_socket_constant_ip_recvtos);
    RING_API_REGISTER("get_ip_recvttl",ring_vm_socket_constant_ip_recvttl);
    RING_API_REGISTER("get_ip_tos",ring_vm_socket_constant_ip_tos);
    RING_API_REGISTER("get_ip_ttl",ring_vm_socket_constant_ip_ttl);
    RING_API_REGISTER("get_ip_unblock_source",ring_vm_socket_constant_ip_unblock_source);
    RING_API_REGISTER("get_ip_unicast_if",ring_vm_socket_constant_ip_unicast_if);
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


