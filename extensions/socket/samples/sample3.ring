load "socket.ring"

host = gethostbyname("google.com") 
? host

see "=========================" + nl
? gethostbyaddr(host)

