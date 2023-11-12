# Copyright 2020 Oscar Guido

# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:

# 1. Redistributions of source code must retain the above copyright notice,
# this list of conditions and the following disclaimer.

# 2. Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.

# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

class TcpServer from ObjectControllerParent
{
  id
  host
  port
  display
  accept_thread

  func TcpServer(id, host, port, display)
  {
    this.id = id
    this.host = host
    this.port = port
    this.display = display
  }

  func init(oParent)
  {
    this.id = oParent.id
    this.host = oParent.host
    this.port = oParent.port
    this.display = oParent.display
  } 

  func start()
  {
    al_init()
    accept_thread = al_create_thread(Method(:run_accept))
  }

  func run_accept()
  {
    display.append("Listen to port: " + port)
    sock = socket(AF_INET, SOCK_STREAM, 0)
    try {
      bind(sock, host, port)
    catch 
      display.append(time() + ": Bind Error!")
      return
    }
    listen(sock, 5)
    accept_loop(sock)
  }

  func accept_loop(sock)
  {
    While True {
      client_sock = accept(sock)
      display.append(time() + ": Accepted a connection!")
      switch receive_loop(client_sock)
      {
        case "bye!"
          display.append(time() + ": Stopping listener!")
          new local { close(client_sock) }
          exit
        else
	  display.append(time() + ": The client disconnected!")
      }
    }
  }

  func receive_loop(client_sock)
  {
    while True {
      switch recv(client_sock, 4)
      {
        case "time"
          display.append(time() + ": Sending current time to client.")
          send(client_sock, time())
        case "bye!"
	  display.append(time() + ": The client sent 'bye!' before disconnecting, that'll be my end!")
          return "bye!"
        else
	  display.append(time() + ": The client signaled disconnection with his unintelligible request!")
          return "next"
      }
    }
  }
}

class local 
