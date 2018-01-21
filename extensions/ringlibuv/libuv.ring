if iswindows()
	LoadLib("ring_uv.dll")
but ismacosx()
	LoadLib("libringuv.dylib")
but islinux() and not isandroid()
	LoadLib("libringuv.so")
ok

Load "ring_libuv.rh"

func uv_walk oloop, cFunc, oArg
	return uv_walk_2(oLoop,
		uv_callback(oLoop,"walk",cFunc),
		oArg)

func uv_close handle, cFunc
	return uv_close_2(handle,
		uv_callback(handle,"close",cFunc))

func uv_timer_start handle, cFunc, timeout, repeat
	return uv_timer_start_2(handle,
		uv_callback(handle,"timer",cFunc),
		timeout,repeat)

func uv_prepare_start prepare, cFunc
	return uv_prepare_start_2(prepare,
		uv_callback(prepare,"prepare",cFunc))

func uv_check_start check, cFunc
	return uv_check_start_2(check,
		uv_callback(check,"check",cFunc))

func uv_idle_start oObj,cFunc
	return uv_idle_start_2(oObj,
		uv_callback(oObj,"idle",cFunc))

func uv_async_init oloop, async, cFunc
	return uv_async_init_2(oLoop,async,
		uv_callback(oLoop,"async",cFunc))

func uv_poll_start handle, events, cFunc
	return uv_poll_start_2(handle,events,
		uv_callback(handle,"poll",cFunc))

func uv_signal_start signal, cFunc, signum
	return uv_signal_start_2(signal,
		uv_callback(signal,"signal",cFunc),
		signum)

func uv_signal_start_oneshot signal, cFunc, signum
	return uv_signal_start_oneshot_2(signal,
		uv_callback(signal,"signal",cFunc),
		signum)

func uv_shutdown req, handle, cFunc
	return uv_shutdown_2(req,handle,
		uv_callback(req,"shutdown",cFunc))

func uv_listen oObj,nOption,cFunc 
	return uv_listen_2(oObj,nOption,uv_callback(oObj,"connect",cFunc))

func uv_read_start stream, cFunc, cFunc2
	return uv_read_start_2(stream,
		uv_callback(stream,"alloc",cFunc),
		uv_callback(stream,"read",cFunc2))

func uv_write req, handle, bufs, nbufs, cFunc
	return uv_write_2(req,handle,bufs,nbufs,
		uv_callback(req,"write",cFunc))

func uv_write2 req, handle, bufs, nbufs, send_handle, cFunc
	return uv_write2_2(req,handle,bufs,nbufs,send_handle,
		uv_callback(req,"write",cFunc))

func uv_tcp_connect oConnect,oSocket,oAddr,cFunc 
	return uv_tcp_connect_2(oConnect,oSocket,oAddr,
		uv_callback(oSocket,"connect",cFunc))

func uv_pipe_connect req, handle, name, cFunc
	return uv_pipe_connect_2(req,handle,name,
		uv_callback(req,"connect",cFunc))

func uv_udp_send req, handle, bufs, nbufs, addr, cFunc
	return uv_udp_send_2(req, handle, bufs, nbufs, addr, 
		uv_callback(req,"udp_send",cFunc))

func uv_udp_recv_start handle, cFunc, cFunc2
	return uv_udp_recv_start_2(handle,
		uv_callback(handle,"alloc",cFunc),
		uv_callback(handle,"udp_recev",cFunc))


