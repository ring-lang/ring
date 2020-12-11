#ifndef ring_socket_h
#define ring_socket_h

struct ring_vm_socket_obj;

void ring_vm_socket_init(void *pPointer);
void ring_vm_socket_bind(void *pPointer);
void ring_vm_socket_listen(void *pPointer);
void ring_vm_socket_accept(void *pPointer);
void ring_vm_socket_send(void *pPointer);
void ring_vm_socket_recv(void *pPointer);
void ring_vm_socket_gethostbyname(void *pPointer);
void ring_vm_socket_gethostbyaddr(void *pPointer);
void ring_vm_socket_connect(void *pPointer);
void ring_vm_socket_close(void *pPointer);
RING_API void ringlib_init(RingState *pRingState);

// MACRO
#define RING_VM_POINTER_SOCKET "socket"

#endif

