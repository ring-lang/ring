Load "guilib.ring"

new qApp {
        oClient = new Client { client() }
        oServer = new Server { server() }
        exec()
}

Class Client

        win1 lineedit1  cOutput=""
        oTcpSocket

        func client

                win1 = new qwidget()

                new qpushbutton(win1) {
                        setgeometry(50,50,100,30)
                        settext("connect")
                        setclickevent("oClient.Connect()")
                }

                lineedit1 = new qtextedit(win1) {
                        setGeometry(150,50,200,300)
                }

                win1 {
                        setwindowtitle("client")
                        setgeometry(10,100,400,400)
                        show()
                }

        func connect
                cOutput = "Connect to host 127.0.0.1 port 9999" + nl
                lineedit1.settext(cOutput)
                oTcpSocket = new qTcpSocket(win1) {
                        setconnectedevent("oClient.pConnected()")
                        setreadyreadevent("oClient.pRead()")
                        connecttohost("127.0.0.1",9999,3,0)
                        waitforconnected(5000)
                }

        func pConnected

                cOutput += "Connected!" + nl
                lineedit1.settext(cOutput)

        func pRead

                cOutput += "Ready Read!" + nl
                lineedit1.settext(cOutput)
                cOutput += oTcpSocket.readall().data() + nl
                lineedit1.settext(cOutput)

Class Server

        win1 lineedit1
        oTcpServer oTcpClient
        cOutput = ""

        func server

                win1 = new qwidget()

                lineedit1 = new qtextedit(win1) {
                        setGeometry(150,50,200,300)
                }

                win1 {
                        setwindowtitle("Server")
                        setgeometry(450,100,400,400)
                        show()
                }

                oTcpServer = new qTcpServer(win1) {
                        setNewConnectionEvent("oServer.pNewConnection()")
                        oHostAddress = new qHostAddress()
                        oHostAddress.SetAddress("127.0.0.1")
                        listen(oHostAddress,9999)
                }
                cOutput = "Server Started" + nl +
                           "listen to port 9999" + nl

                lineedit1.settext(cOutput)

        Func pNewConnection

                oTcpClient = oTcpServer.nextPendingConnection()
                cOutput += "Accept Connection" + nl
                lineedit1.settext(cOutput)
                oTcpClient {
                        cStr ="Hello from server to client!"+char(13)+char(10)
                        write(cStr,len(cStr))
                        flush()
                        waitforbyteswritten(300000)
                        close()
                }
