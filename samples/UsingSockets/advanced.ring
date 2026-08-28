load "sockets.ring" 

# getprotobyname() - protocol number by name
? "getprotobyname('tcp') = " + getprotobyname("tcp")

# getaddrinfo() - modern name-to-address resolution
? "getaddrinfo('127.0.0.1','80') :"
? getaddrinfo("127.0.0.1","80",AF_INET)

server = socket(AF_INET,SOCK_STREAM,0)
setsockopt(server,SOL_SOCKET,SO_REUSEADDR,1)

# getsockopt() - read a socket option
? "SO_TYPE = " + getsockopt(server,SOL_SOCKET,SO_TYPE) + " (SOCK_STREAM = " + SOCK_STREAM + ")"

bind(server,"127.0.0.1",5070)
listen(server,1)

# getsockname() - the local address of the socket
? "server local address:"
? getsockname(server)

client = socket(AF_INET,SOCK_STREAM,0)
connect(client,"127.0.0.1",5070)
conn = accept(server)

# getpeername() - the remote address of the connection
? "client remote address:"
? getpeername(client)

# socketfd() - the raw file descriptor of the socket
? "server file descriptor = " + socketfd(server)

# socklasterror() - the last socket error code
setnonblocking(conn,1)
d = recv(conn,100)                     # nothing to read yet
? "socklasterror() = " + socklasterror() + " (SOCK_EWOULDBLOCK = " + SOCK_EWOULDBLOCK + ")"

# shutdownsocket() - shut down the connection
shutdownsocket(client,SHUT_RDWR)
? "recv after shutdownsocket => '" + recv(conn,100) + "' (empty = peer closed)"

close(conn)
close(client)
close(server)

# terminates use of the Winsock
socketsCleanup()
