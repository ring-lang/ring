load "sockets.ring" 

sock = socket(AF_INET,SOCK_DGRAM,0)
sendto(sock,"Hello Server","127.0.0.1",9090)
msg = recvfrom(sock,1024)
? "Server Say >> " + msg

close(sock)

# terminates use of the Winsock
socketsCleanup()
