load "socket.ring"

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
n = ntohs(21)
? n
? htons(n)
line()
n = htonl(21)
? n
? ntohl(n)

func line ? copy("=",30)
