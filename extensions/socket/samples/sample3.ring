load "socket.ring"

host = gethostbyname("google.com") 
? host

see "=========================" + nl
? gethostbyaddr(host)

see "=========================" + nl
? gethostname()

see "=========================" + nl
? getservbyname("ftp")

see "=========================" + nl
? getservbyport(21)
