load "socket.ring"

host = gethostbyname("google.com")
? host
? copy("=",30)
? gethostbyaddr(host)
? copy("=",30)
? gethostname()
? copy("=",30)
? getservbyname("ftp")
? copy("=",30)
? getservbyport(21)