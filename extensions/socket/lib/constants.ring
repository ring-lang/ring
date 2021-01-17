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

    if isWindows
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
