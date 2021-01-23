load "sockets.ring" 

sock = socket(AF_INET,SOCK_STREAM,0) 
bind(sock,"127.0.0.1",5050)
listen(sock,5)
ns = accept(sock)

send(ns,"Hello Client")
msg = recv(ns,1024)
? "Client Say >> " + msg
close(ns)
close(sock)
? "Socket connection closed"

