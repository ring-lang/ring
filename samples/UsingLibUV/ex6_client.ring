load "libuv.ring"
load "objectslib.ring"

? "Testing RingLibuv - Client Side - Using Classes"

open_object(:MyClient)

Class MyClient from ObjectControllerParent

	DEFAULT_PORT    = 13370
	DEFAULT_BACKLOG = 1024
	
	addr    = new_sockaddr_in()
	connect = NULL
	buffer  = null
	socket  = null
	
	func start
	    myloop  = uv_default_loop()
	    Socket  = new_uv_tcp_t()
	    connect = new_uv_connect_t()
	    uv_tcp_init(myloop, Socket)
	    uv_ip4_addr("127.0.0.1", DEFAULT_PORT, addr)
	    uv_tcp_connect(connect,Socket, addr, Method(:connect))
	    uv_run(myloop, UV_RUN_DEFAULT)
	    destroy_uv_tcp_t(socket)
	    destroy_uv_connect_t(connect)
	
	func connect 
		? "Client: Start Connection"
		aPara   = uv_Eventpara(connect,:connect)
		req     = aPara[1]
		nStatus = aPara[2]
		if nStatus = -1
			? "Error : on_write_end "
			return 
		ok
		buf = new_uv_buf_t()
		message = "hello from the client"
		set_uv_buf_t_len(buf,len(message))
		set_uv_buf_t_base(buf,varptr("message",:char))
		tcp       = get_uv_connect_t_handle(req)
		write_req = new_uv_write_t()
		buf_count = 1
		uv_write(write_req, tcp, buf, buf_count, Method(:on_write_end))
	
	func on_write_end
	    	uv_read_start(socket, uv_myalloccallback(), Method(:echo_read))
	
	func echo_read 
		aPara = uv_Eventpara(socket,:read)
		nRead = aPara[2]
		buf   = aPara[3]
		if nRead > 0
		        wrbuf = uv_buf_init(get_uv_buf_t_base(buf), nread);
			? uv_buf2str(wrbuf)
		ok
	
