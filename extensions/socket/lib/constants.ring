/*
    Author      =>  Abdallah Mohamed Elsharif
    Email       =>  elsharifabdallah53@gmail.com
    Date        =>  10-12-2020
*/

# Protocol Families
    PF_UNSPEC       = 0
    PF_UNIX         = 1
    PF_INET         = 2
    if isWindows()
        PF_INET6        = 23
    else
        PF_INET6        = 10
    ok

# Address Families
    AF_UNSPEC       = 0
    AF_LOCAL        = 1
    AF_UNIX         = PF_UNIX
    PF_FILE         = 1
    AF_INET         = 2
    AF_INET6        = PF_INET6

# Connection Types
    SOCK_STREAM     = 1
    SOCK_DGRAM      = 2
    SOCK_RAW        = 3
    SOCK_RDM        = 4
    SOCK_SEQPACKET  = 5

# Levels
    IPPROTO_IP      = 0
    IPPROTO_TCP     = 6
    IPPROTO_UDP     = 17
    if isWindows()
        SOL_SOCKET      = dec("0xffff")
    else
        SOL_SOCKET      = 1
    ok

# Option names
    SO_DEBUG            = 1

    if isWindows()
        IP_ADD_MEMBERSHIP   = 12
        IP_ADD_SOURCE_MEMBERSHIP = 15
        IP_BLOCK_SOURCE     = 17
        IP_DROP_MEMBERSHIP  = 13
        IP_DROP_SOURCE_MEMBERSHIP = 16
        IP_HDRINCL          = 2
        IP_MTU              = 70
        IP_MTU_DISCOVER     = 71
        IP_MULTICAST_LOOP   = 11
        IP_MULTICAST_TTL    = 10
        IP_OPTIONS          = 1
        IP_PKTINFO          = 19
        IP_RECVTOS          = 40
        IP_RECVTTL          = 21
        IP_TOS              = 3
        IP_TTL              = 4
        IP_UNBLOCK_SOURCE   = 18
        IP_UNICAST_IF       = 31


        SO_ACCEPTCONN       = dec("0x0002")
        SO_BROADCAST        = dec("0x0020")
        SO_DONTROUTE        = dec("0x0010")
        SO_ERROR            = dec("0x1007")
        SO_KEEPALIVE        = dec("0x0008")
        SO_LINGER           = dec("0x0080")
        SO_OOBINLINE        = dec("0x0100")
        SO_RCVBUF           = dec("0x1002")
        SO_REUSEADDR        = dec("0x0004")
        SO_SNDBUF           = dec("0x1001")
        SO_TYPE             = dec("0x1008")
        SO_RCVLOWAT         = dec("0x1004")
        SO_SNDLOWAT         = dec("0x1003")
        SO_RCVTIMEO         = dec("0x1006")
    else
        IP_ADD_MEMBERSHIP   = 35
        IP_ADD_SOURCE_MEMBERSHIP = 39
        IP_BLOCK_SOURCE     = 38
        IP_DROP_MEMBERSHIP  = 36
        IP_DROP_SOURCE_MEMBERSHIP = 40
        IP_HDRINCL          = 3
        IP_MTU              = 14
        IP_MTU_DISCOVER     = 10
        IP_MULTICAST_LOOP   = 34
        IP_MULTICAST_TTL    = 33
        IP_OPTIONS          = 4
        IP_PKTINFO          = 8
        IP_RECVTOS          = 13
        IP_RECVTTL          = 12
        IP_TOS              = 1
        IP_TTL              = 2
        IP_UNBLOCK_SOURCE   = 37
        IP_UNICAST_IF       = 50


        SO_ACCEPTCONN       = 30
        SO_BROADCAST        = 6
        SO_DONTROUTE        = 5
        SO_ERROR            = 4
        SO_KEEPALIVE        = 9
        SO_LINGER           = 13
        SO_OOBINLINE        = 10
        SO_RCVBUF           = 8
        SO_REUSEADDR        = 2
        SO_SNDBUF           = 7
        SO_TYPE             = 3
        SO_RCVLOWAT         = 18
        SO_SNDLOWAT         = 19
        SO_RCVTIMEO         = 20
    ok
