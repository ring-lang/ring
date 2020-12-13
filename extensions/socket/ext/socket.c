/*
    Author      =>  Abdallah Mohamed Elsharif
    Email       =>  elsharifabdallah53@gmail.com
    Date        =>  4-12-2020
*/

#define WIN32_LEAN_AND_MEAN

#include "ring.h"
#include "socket.h"


void ring_vm_socket_init(void *pPointer) {

    if(RING_API_PARACOUNT < 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    } 

    if(!RING_API_ISNUMBER(1) && !RING_API_ISNUMBER(2)) {
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

    RING_SOCKET *sock = (RING_SOCKET *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(RING_SOCKET));

#ifdef win
    WSADATA data;
    sock->addr = NULL;
	if (WSAStartup(MAKEWORD(2, 2), &data) != 0) {
		RING_API_ERROR("WSAStartup failed");
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
        closesocket(sock->sockfd);
        WSACleanup();
        return;
    }


#else
    sock->addr.sin_family = RING_API_GETNUMBER(1);
    int type = RING_API_GETNUMBER(2), opt;

    if((sock->sockfd = socket(sock->addr.sin_family,type,proto)) == 0) {
        RING_API_ERROR("Sock Init Failed");
        return;
    }

    if(setsockopt(sock->sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt))) {
        RING_API_ERROR("Setsockopt Failed");
        return;
    }

#endif  
    
    RING_API_RETCPOINTER(sock,RING_VM_POINTER_SOCKET);
    
}

void ring_vm_socket_bind(void *pPointer) {
    if(RING_API_PARACOUNT != 3) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1) && !RING_API_ISSTRING(2) && !RING_API_ISNUMBER(3)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    const char *host = RING_API_GETSTRING(2);
    const int port = (int) RING_API_GETNUMBER(3);

#ifdef win
    char sPort[10];
    if(getaddrinfo(NULL,itoa(port,sPort,10),&sock->hints,&sock->addr) != 0) {
        RING_API_ERROR("getaddrinfo Falied");
        return;
    }

    if(bind(sock->sockfd ,sock->addr->ai_addr,(int) sock->addr->ai_addrlen) == SOCKET_ERROR) {
        RING_API_ERROR("Bind Error");
        freeaddrinfo(sock->addr);
        closesocket(sock->sockfd);
        WSACleanup();
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
        RING_API_ERROR(RING_API_MISS2PARA);
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
        closesocket(sock->sockfd);
        WSACleanup();
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
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    RING_SOCKET *newsockfd = (RING_SOCKET *) ring_state_malloc(((VM *) pPointer)->pRingState, sizeof(RING_SOCKET));
    
#ifdef win
    if((newsockfd->sockfd = accept(sock->sockfd,(struct sockaddr *) sock->addr,NULL)) == SOCKET_ERROR) {
        RING_API_ERROR("Accept Failed");
        closesocket(sock->sockfd);
        WSACleanup();
        return;
    }

    closesocket(sock->sockfd);
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

    if(!RING_API_ISCPOINTER(1) && !RING_API_ISSTRING(2)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    char *Msg = RING_API_GETSTRING(2);
    
    send(sock->sockfd,Msg,strlen(Msg),0);
    
}

void ring_vm_socket_recv(void *pPointer) {
    if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1) && !RING_API_ISNUMBER(2)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    RING_SOCKET *sock = (RING_SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    int buffer = (int) RING_API_GETNUMBER(2) , bytes_read;
    char Msg[1024];
    bytes_read = recv(sock->sockfd,Msg,buffer,0);
    Msg[bytes_read] = 0;

    RING_API_RETSTRING(Msg);
}

void ring_vm_socket_connect(void *pPointer) {
    if(RING_API_PARACOUNT != 3) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!RING_API_ISCPOINTER(1) && !RING_API_ISSTRING(2) && !RING_API_ISNUMBER(3)) {
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
        WSACleanup();
        return;
    }

    if((n = connect(sock->sockfd,sock->addr->ai_addr,(int) sock->addr->ai_addrlen)) == SOCKET_ERROR) {
        RING_API_ERROR("Connection Refused");
        closesocket(sock->sockfd);
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
        RING_API_ERROR(RING_API_MISS2PARA);
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
    ring_state_free(((VM *) pPointer)->pRingState,sock);
	RING_API_SETNULLPOINTER(1);
}

void ring_vm_socket_gethostbyname(void *pPointer) {
    if(RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS2PARA);
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
    WSADATA data;
    if(WSAStartup(MAKEWORD(2,2),&data) != 0) {
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
        RING_API_ERROR(RING_API_MISS2PARA);
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
    WSADATA data;
    if(WSAStartup(MAKEWORD(2,2),&data) != 0) {
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


RING_API void ringlib_init(RingState *pRingState) {
    ring_vm_funcregister("socket",ring_vm_socket_init);
    ring_vm_funcregister("bind",ring_vm_socket_bind);
    ring_vm_funcregister("listen",ring_vm_socket_listen);
    ring_vm_funcregister("accept",ring_vm_socket_accept);
    ring_vm_funcregister("send",ring_vm_socket_send);
    ring_vm_funcregister("recv",ring_vm_socket_recv);
    ring_vm_funcregister("connect",ring_vm_socket_connect);
    ring_vm_funcregister("close",ring_vm_socket_close);
    ring_vm_funcregister("gethostbyname",ring_vm_socket_gethostbyname);
    ring_vm_funcregister("gethostbyaddr",ring_vm_socket_gethostbyaddr);
}
