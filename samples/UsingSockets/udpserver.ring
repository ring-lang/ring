load "sockets.ring" 

sock = socket(AF_INET,SOCK_DGRAM,0)
bind(sock,"127.0.0.1",9090)
? "UDP Echo Server is running on port 9090 (Ctrl+C to exit)"

while true
	msg = recvfrom(sock,1024)
	? "Client Say >> " + msg
	sendto(sock,"echo: " + msg)
end

close(sock)

# terminates use of the Winsock
socketsCleanup()
