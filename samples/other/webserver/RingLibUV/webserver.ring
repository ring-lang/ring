load "libuv.ring"
load "objectslib.ring"

? "RingLibuv - Simple Web Server!"

DEFAULT_PORT    = 8081
DEFAULT_BACKLOG = 1024

cContent = 	"<html><head><title>Goodbye, world!</title></head>" +
              	"<body>Goodbye, world!</body></html>"

cResponse = "HTTP/1.1 200 OK\r\n" +
            	"Content-Type: text/html\r\n\r\n" +
		cContent
               
cResponse = substr(cResponse,"\r\n",char(13)+char(10))

open_object(:MyWebServer)

class MyWebServer from ObjectControllerParent

	server myloop

	func start

	# Create the Loop
		myloop = new_uv_loop_t()
        	uv_loop_init(myloop)

	# Create the Server and Bind
	        server = new_uv_tcp_t()
        	uv_tcp_init(myloop, server)
		addr    = new_sockaddr_in()
        	uv_ip4_addr("0.0.0.0", DEFAULT_PORT, addr)
	        uv_tcp_bind(server, addr, 0)

	# Listen
	        r = uv_listen(server, DEFAULT_BACKLOG, Method(:newconnection))
        	if r
                	? "Listen error " + uv_strerror(r)
	                return 1
        	ok

	# Start the Main Loop
		? "Start Server!"
	        uv_run(myloop, UV_RUN_DEFAULT)

	# Destroy the handles
	        destroy_uv_tcp_t(server)

func newconnection

	# Check Status
	        aPara   = uv_Eventpara(server,:connect)
        	nStatus = aPara[UV_EVENTPARA_STATUS]
	        if nStatus < 0
        	        ? "New connection error : " + nStatus
                	return
	        ok

	# Deal with the New Client
		open_object(:NewClient)
		last_object().nCallBacksCount = uv_callbackscount()
		last_object().Accept(myloop,server)

class NewClient from ObjectControllerParent

	client req buf oShutdown

	nCallBacksCount

	func Start
        	client = new_uv_tcp_t()

	func Accept myloop,server
        	uv_tcp_init(myloop, client)
	        if uv_accept(server, client) = 0
        	        uv_read_start(client, uv_myalloccallback(), Method(:GetRequest))
		else 
			uv_close(client,"")
	        ok
	
	func GetRequest
        	aPara = uv_Eventpara(client,:read)
	        nRead = aPara[UV_EVENTPARA_SIZE]
        	buf   = aPara[UV_EVENTPARA_BUFFER]
		# Delete buf
			CleanBuffer(buf)
	        if nRead > 0
        	        req = new_uv_write_t()			
			buf = new_uv_buf_t()
        	        set_uv_buf_t_len(buf,len(cResponse))
                	set_uv_buf_t_base(buf,varptr(:cResponse,:char))
	                uv_write(req, client, buf, 1, Method(:Finish))
	        ok

	func Finish
		oShutdown = new_uv_shutdown_t()
		uv_shutdown(oShutdown,get_uv_write_t_handle(req),Method(:MyShutdown))

	func MyShutdown
		aPara = uv_Eventpara(client,:read)
		uv_deletecallbacksafter(nCallBacksCount)
		destroy_uv_shutdown_t(oShutdown)
		CleanBuffer(buf)
		destroy_uv_write_t(req)
		close()

	func CleanBuffer buf
		pBase = get_uv_buf_t_base(buf)
		uv_free(pBase)
		uv_free(buf)
		destroy_uv_buf_t(buf)

