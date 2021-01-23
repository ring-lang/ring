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

class ServerWindow
{
  tcpServer
  outputEdit

  func ServerWindow(instance, host, port)
  {
    w = 100
    h = 30
    x = 25
    y = 25
    s = 5
    window = new QWidget()
    {
      setWindowTitle("Server: "+ host +" "+ port )
      setGeometry(10,100,800,600)
    }
    hostLabel = new QLabel(window)
    {
      setText("Host:")
      setGeometry(x,y,w,h)
    }
    hostEdit = new QTextEdit(window)
    {
      setText(Host)
      setGeometry(x+w+s, y, w, h)
    }
    portLabel = new QLabel(window)
    {
      setText("Port:")
      setGeometry(x, y+h+s, w, h)
    }
    portEdit = new QTextEdit(window)
    {
      setText(Port)
      setGeometry(x+w+s, y+h+s, w, h)
    }
    this.outputEdit = new QTextEdit(window)
    {
      setText(date() + "-" + time() + nl + "Italo-hispanic server, olé!" + nl)
      setGeometry(x, y+3*(h+s), 7*w, 10*h)
      setReadOnly(1)
    }
    this.tcpServer = new TcpServer{TcpServer("tcpServer", "127.0.0.1", 5051, this.outputEdit)}
    listenBtn = new QPushButton(window)
    {
      setText("Listen")
      setGeometry(x, y+2*(h+s), w, h)
      setClickEvent(instance+".listenClicked()")
    }
    window.show()
  }

  func listenClicked()
  {
	CreateObject(:TcpServer,this.tcpServer)
  }
}
