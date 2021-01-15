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
    but isLinux()
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
    but isLinux()
        SOL_SOCKET      = 1
    ok
