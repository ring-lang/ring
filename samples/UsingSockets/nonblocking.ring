load "sockets.ring" 

# socketpair() creates two connected sockets (no second process needed)
sp = socketpair(AF_UNIX,SOCK_STREAM,0)
s1 = sp[1]
s2 = sp[2]

# make both ends non-blocking
setnonblocking(s1,1)
setnonblocking(s2,1)

send(s1,"Hello")

# wait (up to 1 second) until s2 is ready to read
r = []
add(r,s2)
ready = select(r,[],[],1)
? "sockets ready to read: " + len(ready[1])

? "Received >> " + recv(s2,1024)

close(s1)
close(s2)

# terminates use of the Winsock
socketsCleanup()
