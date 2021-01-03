load 'socket.ring'

sock = socket(AF_INET,SOCK_DGRAM)
connect(sock,"127.0.0.1",5050)
sendto(sock,"Hello Server")
msg = recvfrom(sock,1024)
? "Server Say >> " + msg
close(sock)
? "Socket connection closed"
