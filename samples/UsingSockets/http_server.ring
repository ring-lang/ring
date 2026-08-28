load "sockets.ring"

PORT = 8080

listen_sock = socket(AF_INET, SOCK_STREAM, 0)
# SO_REUSEADDR: allow immediate re-bind after restart (skip TIME_WAIT)
setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, 1)
bind(listen_sock, "0.0.0.0", PORT)
listen(listen_sock, 128)
# Non-blocking: accept()/recv() return immediately instead of waiting
setnonblocking(listen_sock, 1)

clients = []
dead = []

? "Non-blocking http server on http://127.0.0.1:" + PORT + "  (Ctrl-C to stop)"

while true
    # Build the read-set: listener + every connected client
    rset = []
    add(rset, listen_sock)
    for c in clients
        add(rset, c)
    next

    ready = select(rset, [], [], 1)

    # ready[1] is the list of sockets ready to read
    for sock in ready[1]
        if socketfd(sock) = socketfd(listen_sock)
            # Accept every pending connection (non-blocking)
            ns = accept(listen_sock)
            if not isNull(ns)
                setnonblocking(ns, 1)
                add(clients, ns)
            ok
        else
            # A client sent data (or closed)
            data = recv(sock, 4096)

            # recv() returns NULL on "would block" (no data yet) - ignore that case
            if not (isNull(data) and socklasterror() = SOCK_EWOULDBLOCK)
                if isNull(data)
                    # Peer closed the connection
                    fd = socketfd(sock)
                    close(sock)
                    add(dead, fd)
                else
                    fd = socketfd(sock)
                    body = "Hello from the Ring http server!<br>" +
                           "You sent: " + trim(data)
                    header = "HTTP/1.0 200 OK" + char(13) + nl +
                             "Content-Type: text/html" + char(13) + nl +
                             "Content-Length: " + len(body) + char(13) + nl +
                             "Connection: close" + char(13) + nl + char(13) + nl
                    send(sock, header + body)
                    close(sock)
                    add(dead, fd)
                ok
            ok
        ok
    next

    # Drop closed clients from the set
    if len(dead) > 0
        alive = []
        for c in clients
            drop = 0
            for d in dead
                if socketfd(c) = d drop = 1 ok
            next
            if drop = 0 add(alive, c) ok
        next
        clients = alive
        dead = []
    ok
end

close(listen_sock)
