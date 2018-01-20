if iswindows()
	LoadLib("ring_uv.dll")
but ismacosx()
	LoadLib("libringuv.dylib")
but islinux() and not isandroid()
	LoadLib("libringuv.so")
ok
Load "ring_libuv.rh"

func uv_idle_start oObj,cFunc
	uv_idle_start_2(oObj,uv_callback(oObj,"idle",cFunc))

