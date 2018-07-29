load "libsdl.ring"

C_PORT = 8081

cResponse = "HTTP/1.1 200 OK\r\n" +
            	"Content-Type: text/html\r\n\r\n"
cResponse = substr(cResponse,"\r\n",char(13)+char(10))
cContent = 	"<html><head><title>Goodbye, world!</title></head>" +
              	"<body>Welcome to Network Programming!!</body></html>"
cResponse += cContent 

nCount = 0

func main 
	? "Web Server - Port " + C_PORT
	sdlnet_init()
	oAddress = sdl_new_ipaddress()
	SDLNet_ResolveHost(oAddress,"0.0.0.0",C_PORT)
	oServer = SDLNet_Tcp_Open(oAddress)
	mydata = space(400) 
	pData = varptr(:mydata,"void")
	pResponse = varptr(:cResponse,"void")
	nSize = len(cResponse)
	while True 
		NewClient(oServer,mydata,pData,pResponse,nSize)
	end
	? sdlnet_quit()
	
func NewClient oServer,mydata,pData,pResponse,nSize
	oSocket = SDLNet_Tcp_Accept(oServer)
	if ptrcmp(oSocket,NULL) = False
		sdlnet_tcp_recv(oSocket,pData,400)
		sdlnet_tcp_send(oSocket,pResponse,nSize)
		SDLNet_tcp_close(oSocket)
	ok
