load "socket.ring"

host = gethostbyname("google.com")
? host
line()
? gethostbyaddr(host)
line()
? gethostname()
line()
? getservbyname("ftp")
line()
? getservbyport(21)

func line ? copy("=",30)