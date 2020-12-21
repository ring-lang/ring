
# UDP SERVER

load 'socket.ring'

sock = socket(AF_INET,SOCK_DGRAM)
bind(sock,"127.0.0.1",5050)

while true
    msg = recvfrom(sock,1024)
    ? "Client Say >> " + msg
    sendto(sock,"Hello Client")
    close(sock)
    exit
end

? "socket connection closed"