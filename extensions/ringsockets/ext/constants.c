/*
    Modified    =>  Youssef Saeed (youssefelkholey@gmail.com)
    Date        =>  28-8-2026
    Changes     =>  New constant functions with portable fallbacks
                    (-1 where unsupported).
*/

#include "constants.h"

void ring_vm_socket_constant_pf_unspec(void *pPointer)
{
    RING_API_RETNUMBER(PF_UNSPEC);
}

void ring_vm_socket_constant_pf_unix(void *pPointer)
{
    RING_API_RETNUMBER(PF_UNIX);
}

void ring_vm_socket_constant_pf_inet(void *pPointer)
{
    RING_API_RETNUMBER(PF_INET);
}

void ring_vm_socket_constant_pf_inet6(void *pPointer)
{
    RING_API_RETNUMBER(PF_INET6);
}

void ring_vm_socket_constant_af_unspec(void *pPointer)
{
    RING_API_RETNUMBER(AF_UNSPEC);
}

void ring_vm_socket_constant_af_unix(void *pPointer)
{
    RING_API_RETNUMBER(AF_UNIX);
}

void ring_vm_socket_constant_af_inet(void *pPointer)
{
    RING_API_RETNUMBER(AF_INET);
}

void ring_vm_socket_constant_af_inet6(void *pPointer)
{
    RING_API_RETNUMBER(AF_INET6);
}

void ring_vm_socket_constant_sock_stream(void *pPointer)
{
    RING_API_RETNUMBER(SOCK_STREAM);
}

void ring_vm_socket_constant_sock_dgram(void *pPointer)
{
    RING_API_RETNUMBER(SOCK_DGRAM);
}

void ring_vm_socket_constant_sock_raw(void *pPointer)
{
    RING_API_RETNUMBER(SOCK_RAW);
}

void ring_vm_socket_constant_sock_rdm(void *pPointer)
{
    RING_API_RETNUMBER(SOCK_RDM);
}

void ring_vm_socket_constant_sock_seqpacket(void *pPointer)
{
    RING_API_RETNUMBER(SOCK_SEQPACKET);
}

void ring_vm_socket_constant_ipproto_ip(void *pPointer)
{
    RING_API_RETNUMBER(IPPROTO_IP);
}

void ring_vm_socket_constant_ipproto_tcp(void *pPointer)
{
    RING_API_RETNUMBER(IPPROTO_TCP);
}

void ring_vm_socket_constant_ipproto_udp(void *pPointer)
{
    RING_API_RETNUMBER(IPPROTO_UDP);
}

void ring_vm_socket_constant_sol_socket(void *pPointer)
{
    RING_API_RETNUMBER(SOL_SOCKET);
}

void ring_vm_socket_constant_ipproto_raw(void *pPointer)
{
    RING_API_RETNUMBER(IPPROTO_RAW);
}

void ring_vm_socket_constant_ipproto_icmp(void *pPointer)
{
    RING_API_RETNUMBER(IPPROTO_ICMP);
}

void ring_vm_socket_constant_ipproto_igmp(void *pPointer)
{
    RING_API_RETNUMBER(IPPROTO_IGMP);
}

void ring_vm_socket_constant_ipproto_sctp(void *pPointer)
{
#ifdef IPPROTO_SCTP
    RING_API_RETNUMBER(IPPROTO_SCTP);
#else
    RING_API_RETNUMBER(-1);
#endif
}

void ring_vm_socket_constant_so_debug(void *pPointer)
{
    RING_API_RETNUMBER(SO_DEBUG);
}

void ring_vm_socket_constant_ip_add_membership(void *pPointer)
{
    RING_API_RETNUMBER(IP_ADD_MEMBERSHIP);
}

void ring_vm_socket_constant_ip_add_source_membership(void *pPointer)
{
    RING_API_RETNUMBER(IP_ADD_SOURCE_MEMBERSHIP);
}

void ring_vm_socket_constant_ip_block_source(void *pPointer)
{
    RING_API_RETNUMBER(IP_BLOCK_SOURCE);
}

void ring_vm_socket_constant_ip_drop_membership(void *pPointer)
{
    RING_API_RETNUMBER(IP_DROP_MEMBERSHIP);
}

void ring_vm_socket_constant_ip_drop_source_membership(void *pPointer)
{
    RING_API_RETNUMBER(IP_DROP_SOURCE_MEMBERSHIP);
}

void ring_vm_socket_constant_ip_hdrincl(void *pPointer)
{
    RING_API_RETNUMBER(IP_HDRINCL);
}

/*
void ring_vm_socket_constant_ip_mtu(void *pPointer)
{
    RING_API_RETNUMBER(IP_MTU);
}

void ring_vm_socket_constant_ip_mtu_discover(void *pPointer)
{
    RING_API_RETNUMBER(IP_MTU_DISCOVER);
}
*/

void ring_vm_socket_constant_ip_multicast_loop(void *pPointer)
{
    RING_API_RETNUMBER(IP_MULTICAST_LOOP);
}

void ring_vm_socket_constant_ip_multicast_ttl(void *pPointer)
{
    RING_API_RETNUMBER(IP_MULTICAST_TTL);
}

void ring_vm_socket_constant_ip_options(void *pPointer)
{
    RING_API_RETNUMBER(IP_OPTIONS);
}

void ring_vm_socket_constant_ip_pktinfo(void *pPointer)
{
    RING_API_RETNUMBER(IP_PKTINFO);
}

void ring_vm_socket_constant_ip_recvtos(void *pPointer)
{
    RING_API_RETNUMBER(IP_RECVTOS);
}

void ring_vm_socket_constant_ip_recvttl(void *pPointer)
{
    RING_API_RETNUMBER(IP_RECVTTL);
}

void ring_vm_socket_constant_ip_tos(void *pPointer)
{
    RING_API_RETNUMBER(IP_TOS);
}

void ring_vm_socket_constant_ip_ttl(void *pPointer)
{
    RING_API_RETNUMBER(IP_TTL);
}

void ring_vm_socket_constant_ip_unblock_source(void *pPointer)
{
    RING_API_RETNUMBER(IP_UNBLOCK_SOURCE);
}

/*
void ring_vm_socket_constant_ip_unicast_if(void *pPointer)
{
    RING_API_RETNUMBER(IP_UNICAST_IF);
}
*/

void ring_vm_socket_constant_so_acceptconn(void *pPointer)
{
    RING_API_RETNUMBER(SO_ACCEPTCONN);
}

void ring_vm_socket_constant_so_broadcast(void *pPointer)
{
    RING_API_RETNUMBER(SO_BROADCAST);
}

void ring_vm_socket_constant_so_dontroute(void *pPointer)
{
    RING_API_RETNUMBER(SO_DONTROUTE);
}

void ring_vm_socket_constant_so_error(void *pPointer)
{
    RING_API_RETNUMBER(SO_ERROR);
}

void ring_vm_socket_constant_so_keepalive(void *pPointer)
{
    RING_API_RETNUMBER(SO_KEEPALIVE);
}

void ring_vm_socket_constant_so_linger(void *pPointer)
{
    RING_API_RETNUMBER(SO_LINGER);
}

void ring_vm_socket_constant_so_oobinline(void *pPointer)
{
    RING_API_RETNUMBER(SO_OOBINLINE);
}

void ring_vm_socket_constant_so_rcvbuf(void *pPointer)
{
    RING_API_RETNUMBER(SO_RCVBUF);
}

void ring_vm_socket_constant_so_reuseaddr(void *pPointer)
{
    RING_API_RETNUMBER(SO_REUSEADDR);
}

void ring_vm_socket_constant_so_sndbuf(void *pPointer)
{
    RING_API_RETNUMBER(SO_SNDBUF);
}

void ring_vm_socket_constant_so_type(void *pPointer)
{
    RING_API_RETNUMBER(SO_TYPE);
}

void ring_vm_socket_constant_so_rcvlowat(void *pPointer)
{
    RING_API_RETNUMBER(SO_RCVLOWAT);
}

void ring_vm_socket_constant_so_sndlowat(void *pPointer)
{
    RING_API_RETNUMBER(SO_SNDLOWAT);
}

void ring_vm_socket_constant_so_rcvtimeo(void *pPointer)
{
    RING_API_RETNUMBER(SO_RCVTIMEO);
}

void ring_vm_socket_constant_so_sndtimeo(void *pPointer)
{
    RING_API_RETNUMBER(SO_SNDTIMEO);
}

void ring_vm_socket_constant_so_exclusiveaddruse(void *pPointer)
{
#ifdef SO_EXCLUSIVEADDRUSE
    RING_API_RETNUMBER(SO_EXCLUSIVEADDRUSE);
#else
    RING_API_RETNUMBER(-1);
#endif
}

void ring_vm_socket_constant_so_nosigpipe(void *pPointer)
{
#ifdef SO_NOSIGPIPE
    RING_API_RETNUMBER(SO_NOSIGPIPE);
#else
    RING_API_RETNUMBER(-1);
#endif
}

void ring_vm_socket_constant_so_reuseport(void *pPointer)
{
#ifdef SO_REUSEPORT
    RING_API_RETNUMBER(SO_REUSEPORT);
#else
    RING_API_RETNUMBER(-1);
#endif
}

void ring_vm_socket_constant_shut_rd(void *pPointer)
{
#ifdef SHUT_RD
    RING_API_RETNUMBER(SHUT_RD);
#elif defined(SD_RECEIVE)
    RING_API_RETNUMBER(SD_RECEIVE);
#else
    RING_API_RETNUMBER(0);
#endif
}

void ring_vm_socket_constant_shut_wr(void *pPointer)
{
#ifdef SHUT_WR
    RING_API_RETNUMBER(SHUT_WR);
#elif defined(SD_SEND)
    RING_API_RETNUMBER(SD_SEND);
#else
    RING_API_RETNUMBER(1);
#endif
}

void ring_vm_socket_constant_shut_rdwr(void *pPointer)
{
#ifdef SHUT_RDWR
    RING_API_RETNUMBER(SHUT_RDWR);
#elif defined(SD_BOTH)
    RING_API_RETNUMBER(SD_BOTH);
#else
    RING_API_RETNUMBER(2);
#endif
}

void ring_vm_socket_constant_sock_ewouldblock(void *pPointer)
{
#ifdef _WIN32
    RING_API_RETNUMBER(WSAEWOULDBLOCK);
#else
    RING_API_RETNUMBER(EAGAIN);
#endif
}

void ring_vm_socket_constant_tcp_nodelay(void *pPointer)
{
    RING_API_RETNUMBER(TCP_NODELAY);
}

void ring_vm_socket_constant_tcp_keepidle(void *pPointer)
{
#ifdef TCP_KEEPIDLE
    RING_API_RETNUMBER(TCP_KEEPIDLE);
#else
    RING_API_RETNUMBER(-1);
#endif
}

void ring_vm_socket_constant_tcp_keepintvl(void *pPointer)
{
#ifdef TCP_KEEPINTVL
    RING_API_RETNUMBER(TCP_KEEPINTVL);
#else
    RING_API_RETNUMBER(-1);
#endif
}

void ring_vm_socket_constant_tcp_keepcnt(void *pPointer)
{
#ifdef TCP_KEEPCNT
    RING_API_RETNUMBER(TCP_KEEPCNT);
#else
    RING_API_RETNUMBER(-1);
#endif
}

void ring_vm_socket_constant_msg_oob(void *pPointer)
{
    RING_API_RETNUMBER(MSG_OOB);
}

void ring_vm_socket_constant_msg_peek(void *pPointer)
{
    RING_API_RETNUMBER(MSG_PEEK);
}

void ring_vm_socket_constant_msg_waitall(void *pPointer)
{
#ifdef MSG_WAITALL
    RING_API_RETNUMBER(MSG_WAITALL);
#else
    RING_API_RETNUMBER(-1);
#endif
}

void ring_vm_socket_constant_msg_dontwait(void *pPointer)
{
#ifdef MSG_DONTWAIT
    RING_API_RETNUMBER(MSG_DONTWAIT);
#else
    RING_API_RETNUMBER(-1);
#endif
}
