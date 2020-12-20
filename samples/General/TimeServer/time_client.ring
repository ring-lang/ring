load "stdlib.ring"
load "socket.ring"
sock = socket(AF_INET, SOCK_STREAM)
connect(sock, "127.0.0.1", 5051)
see "Enter 'time' to get the time or anything else to exit." + nl
main_loop(sock)

func main_loop(sock)
{
  switch getstring()
  {
    case "time"
      send(sock, "time")
      the_time = recv(sock, 1024)
      see "The time is " + the_time + nl
      main_loop(sock)
    else
      send(sock, "bye!")
      close(sock)
  }
}
