load "guilib.ring"
 
cResponse = "HTTP/1.1 200 OK\r\n" +
               "Content-Type: text/html\r\n\r\n" +
               "<html><head><title>Goodbye, world!</title></head>" +
               "<body>Goodbye, world!</body></html>"
 
cResponse = substr(cResponse,"\r\n",char(13)+char(10))
 
oApp = new qApp {
		oServer = new Server { Server() }
		exec()
}
 
class Server

        oTcpServer oTcpClient

        func Server
                oTcpServer = new qTcpServer(NULL) 
                oTcpServer.setNewConnectionEvent("oServer.NewConnection()")
                oHostAddress = new qHostAddress()
                oHostAddress.SetAddress("127.0.0.1")
                oTcpServer.listen(oHostAddress,8081)                
                ? "Server Started" + nl +
                  "listen to port 8081" 
 
        func NewConnection
                oTcpClient = oTcpServer.nextPendingConnection()
                while not oTcpClient.waitForReadyRead(100) end
		oTcpClient.ReadAll()
                oTcpClient.write(cResponse,len(cResponse))
		oTcpClient.flush()
		oTcpClient.waitforbyteswritten(300000)
		oTcpClient.close()
		oTcpClient.deleteLater()