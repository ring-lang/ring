if iswindows()
	LoadLib("ring_uv.dll")
but ismacosx()
	LoadLib("libringuv.dylib")
but islinux() and not isandroid()
	LoadLib("libringuv.so")
ok

Load "ring_libuv.rh"

func uv_idle_start oObj,cFunc
	return uv_idle_start_2(oObj,uv_callback(oObj,"idle",cFunc))

func uv_listen oObj,nOption,cFunc 
	return uv_listen_2(oObj,nOption,uv_callback(oObj,"connect",cFunc))

func uv_tcp_connect oConnect,oSocket,oAddr,cFunc 
	return uv_tcp_connect_2(oConnect,oSocket,oAddr,
		uv_callback(oSocket,"connect",cFunc) )

func uv_walk oloop, cFunc, oArg
	return uv_walk_2(oLoop,
		uv_callback(oLoop,"walk",cFunc),
		oArg)

