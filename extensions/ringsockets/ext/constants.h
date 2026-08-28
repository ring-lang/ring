/*
    Modified    =>  Youssef Saeed (youssefelkholey@gmail.com)
    Date        =>  28-8-2026
    Changes     =>  Declarations for new constants (TCP options, message
                    flags, shutdown flags, protocols, SOCK_EWOULDBLOCK).
*/

#ifndef HAVE_RING_SOCKET_CONSTANTS
#define HAVE_RING_SOCKET_CONSTANTS

#include "sockets.h"


/* Protocol Families */
void ring_vm_socket_constant_pf_unspec(void *pPointer);
void ring_vm_socket_constant_pf_unix(void *pPointer);
void ring_vm_socket_constant_pf_inet(void *pPointer);
void ring_vm_socket_constant_pf_inet6(void *pPointer);

/* Address Families */
void ring_vm_socket_constant_af_unspec(void *pPointer);
void ring_vm_socket_constant_af_unix(void *pPointer);
void ring_vm_socket_constant_af_inet(void *pPointer);
void ring_vm_socket_constant_af_inet6(void *pPointer);

/* Connection Types */
void ring_vm_socket_constant_sock_stream(void *pPointer);
void ring_vm_socket_constant_sock_dgram(void *pPointer);
void ring_vm_socket_constant_sock_raw(void *pPointer);
void ring_vm_socket_constant_sock_rdm(void *pPointer);
void ring_vm_socket_constant_sock_seqpacket(void *pPointer);

/* Levels */
void ring_vm_socket_constant_ipproto_ip(void *pPointer);
void ring_vm_socket_constant_ipproto_tcp(void *pPointer);
void ring_vm_socket_constant_ipproto_udp(void *pPointer);
void ring_vm_socket_constant_ipproto_raw(void *pPointer);
void ring_vm_socket_constant_ipproto_icmp(void *pPointer);
void ring_vm_socket_constant_ipproto_igmp(void *pPointer);
void ring_vm_socket_constant_ipproto_sctp(void *pPointer);
void ring_vm_socket_constant_sol_socket(void *pPointer);

/* TCP socket options */
void ring_vm_socket_constant_tcp_nodelay(void *pPointer);
void ring_vm_socket_constant_tcp_keepidle(void *pPointer);
void ring_vm_socket_constant_tcp_keepintvl(void *pPointer);
void ring_vm_socket_constant_tcp_keepcnt(void *pPointer);

/* Message flags */
void ring_vm_socket_constant_msg_oob(void *pPointer);
void ring_vm_socket_constant_msg_peek(void *pPointer);
void ring_vm_socket_constant_msg_waitall(void *pPointer);
void ring_vm_socket_constant_msg_dontwait(void *pPointer);

/* Additional socket options */
void ring_vm_socket_constant_so_sndtimeo(void *pPointer);
void ring_vm_socket_constant_so_exclusiveaddruse(void *pPointer);
void ring_vm_socket_constant_so_nosigpipe(void *pPointer);
void ring_vm_socket_constant_so_reuseport(void *pPointer);

/* Shutdown flags */
void ring_vm_socket_constant_shut_rd(void *pPointer);
void ring_vm_socket_constant_shut_wr(void *pPointer);
void ring_vm_socket_constant_shut_rdwr(void *pPointer);

/* Would-block error code (portable) */
void ring_vm_socket_constant_sock_ewouldblock(void *pPointer);

/* Option names */
void ring_vm_socket_constant_so_debug(void *pPointer);
void ring_vm_socket_constant_ip_add_membership(void *pPointer);
void ring_vm_socket_constant_ip_add_source_membership(void *pPointer);
void ring_vm_socket_constant_ip_block_source(void *pPointer);
void ring_vm_socket_constant_ip_drop_membership(void *pPointer);
void ring_vm_socket_constant_ip_drop_source_membership(void *pPointer);
void ring_vm_socket_constant_ip_hdrincl(void *pPointer);
/*
void ring_vm_socket_constant_ip_mtu(void *pPointer);
void ring_vm_socket_constant_ip_mtu_discover(void *pPointer);
*/
void ring_vm_socket_constant_ip_multicast_loop(void *pPointer);
void ring_vm_socket_constant_ip_multicast_ttl(void *pPointer);
void ring_vm_socket_constant_ip_options(void *pPointer);
/*
void ring_vm_socket_constant_ip_pktinfo(void *pPointer);
*/
void ring_vm_socket_constant_ip_recvtos(void *pPointer);
void ring_vm_socket_constant_ip_recvttl(void *pPointer);
void ring_vm_socket_constant_ip_tos(void *pPointer);
void ring_vm_socket_constant_ip_ttl(void *pPointer);
void ring_vm_socket_constant_ip_unblock_source(void *pPointer);
/*
void ring_vm_socket_constant_ip_unicast_if(void *pPointer);
*/
void ring_vm_socket_constant_so_acceptconn(void *pPointer);
void ring_vm_socket_constant_so_broadcast(void *pPointer);
void ring_vm_socket_constant_so_dontroute(void *pPointer);
void ring_vm_socket_constant_so_error(void *pPointer);
void ring_vm_socket_constant_so_keepalive(void *pPointer);
void ring_vm_socket_constant_so_linger(void *pPointer);
void ring_vm_socket_constant_so_oobinline(void *pPointer);
void ring_vm_socket_constant_so_rcvbuf(void *pPointer);
void ring_vm_socket_constant_so_reuseaddr(void *pPointer);
void ring_vm_socket_constant_so_sndbuf(void *pPointer);
void ring_vm_socket_constant_so_type(void *pPointer);
void ring_vm_socket_constant_so_rcvlowat(void *pPointer);
void ring_vm_socket_constant_so_sndlowat(void *pPointer);
void ring_vm_socket_constant_so_rcvtimeo(void *pPointer);

#endif