/*
    Author      =>  Abdallah Mohamed Elsharif
    Email       =>  elsharifabdallah53@gmail.com
    Date        =>  4-12-2020
*/


#include "ring.h"
#include "socket.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

typedef struct ring_vm_socket_obj {

    int sockfd;
    struct sockaddr_in addr;

} SOCKET;



void ring_vm_socket_init(void *pPointer) {

    SOCKET *sock = (SOCKET *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(SOCKET));
    int proto = 0, opt;

    if(RING_API_PARACOUNT < 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    } 

    if(!RING_API_ISNUMBER(1) && !RING_API_ISNUMBER(2)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    sock->addr.sin_family = RING_API_GETNUMBER(1);
    int type = RING_API_GETNUMBER(2);

    if(RING_API_PARACOUNT == 3) {
        if(!RING_API_ISNUMBER(3)) {
            RING_API_ERROR(RING_API_BADPARATYPE);
            return;
        }

        proto = (int) RING_API_GETNUMBER(3);
    }


    if((sock->sockfd = socket(sock->addr.sin_family,type,proto)) == 0) {
        RING_API_ERROR("Failed sock init");
        return;
    }

    if(setsockopt(sock->sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt))) {
        RING_API_ERROR("Failed in setsockopt");
        return;
    }
    
    
    RING_API_RETCPOINTER(sock,RING_VM_POINTER_SOCKET);
    
}

void ring_vm_socket_bind(void *pPointer) {
    if(RING_API_PARACOUNT != 3) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!RING_API_ISSTRING(2) && !RING_API_ISNUMBER(3)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    SOCKET *sock = (SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    const char *host = RING_API_GETSTRING(2);
    const int port = (int) RING_API_GETNUMBER(3);
    sock->addr.sin_addr.s_addr = inet_addr(host);
    sock->addr.sin_port = htons(port);

    if(bind(sock->sockfd,(struct sockaddr *)&sock->addr,sizeof(sock->addr)) < 0) {
        RING_API_ERROR("Error in Bind");
        return;
    }

}

void ring_vm_socket_listen(void *pPointer) {
 
    SOCKET *sock = (SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
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

    if(listen(sock->sockfd,n) < 0) {
        RING_API_ERROR("Listen Failed");
        return;
    }
    
}

void ring_vm_socket_accept(void *pPointer) {
    SOCKET *sock = (SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    SOCKET *newsockfd = (SOCKET *) ring_state_malloc(((VM *) pPointer)->pRingState, sizeof(SOCKET));
    int addr_len = sizeof(sock->addr);
    if((newsockfd->sockfd = accept(sock->sockfd,(struct sockaddr *)&sock->addr,(socklen_t *)&addr_len)) < 0)
    {
        RING_API_ERROR("Error in get session");
        return;
    }

    RING_API_RETCPOINTER(newsockfd,RING_VM_POINTER_SOCKET);
}

void ring_vm_socket_send(void *pPointer) {
    if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!RING_API_ISSTRING(2)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    SOCKET *sockfd = (SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    char *Msg = RING_API_GETSTRING(2);
    
    send(sockfd->sockfd,Msg,strlen(Msg),0);
    
}

void ring_vm_socket_recv(void *pPointer) {
    if(RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!RING_API_ISNUMBER(2)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    SOCKET *sockfd = (SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    int buffer = (int) RING_API_GETNUMBER(2);

    char Msg[buffer];
    recv(sockfd->sockfd,Msg,buffer,0);

    RING_API_RETSTRING(Msg);
}

void ring_vm_socket_connect(void *pPointer) {
    if(RING_API_PARACOUNT != 3) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if(!RING_API_ISSTRING(2) && !RING_API_ISNUMBER(3)) {
        RING_API_ERROR(RING_API_BADPARATYPE);
        return;
    }

    SOCKET *sock = (SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    char *host = RING_API_GETSTRING(2);
    int port = (int) RING_API_GETNUMBER(3) , n;
    

    sock->addr.sin_port = htons(port);

    if(inet_pton(sock->addr.sin_family,host,&sock->addr.sin_addr) <= 0) {
        RING_API_ERROR("Invalid address");
        return;
    }

    if((n = connect(sock->sockfd,(struct sockaddr *) &sock->addr,sizeof(sock->addr))) < 0) {
        RING_API_ERROR("Connection Refused");
        return;
    }

    RING_API_RETNUMBER(n);
}

void ring_vm_socket_close(void *pPointer) {
    if (RING_API_PARACOUNT != 1) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    SOCKET *sock = (SOCKET *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SOCKET);
    close(sock->sockfd);
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
#ifdef h_addr
    for(temp = host_entry->h_addr_list; *temp; temp++) {
        ring_list_addstring(ringval,inet_ntoa(*((struct in_addr *) temp)));
    }
#else
    ring_list_addstring(ringval,inet_ntoa(*((struct in_addr *) host_entry->h_addr)));
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
