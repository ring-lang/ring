load "sockets.ring"

host = gethostbyname("google.com")
? host
line()
? gethostbyaddr(host)
line()
? gethostname()
line()
? getservbyname("ftp")
? getservbyname("syslog","udp")
line()
? getservbyport(21)
? getservbyport(514,"udp")
line()
n = htons(21)
? n
? ntohs(n)
line()
n = htonl(21)
? n
? ntohl(n)
line()
addr = inet_addr("127.0.0.1")
? inet_ntoa(addr)
line()
addr = inet_pton(AF_INET6, "::1")
? inet_ntop(AF_INET6, addr)

# terminates use of the Winsock
socketsCleanup()

func line ? copy("=",30)

