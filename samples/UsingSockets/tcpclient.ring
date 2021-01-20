load "sockets.ring" 

sock = socket(AF_INET,SOCK_STREAM)
connect(sock,"127.0.0.1",5050)

send(sock,"Hello Server")
msg = recv(sock,1024)
? "Server Say >> " + msg

close(sock)
? "Socket connection closed"

