load "libuv.ring"

counter = 0
idler = NULL 

func main
	idler = new_uv_idle_t()
	uv_idle_init(uv_default_loop(), idler)
	uv_idle_start(idler, "wait()")
	? "Idling..."
	uv_run(uv_default_loop(), UV_RUN_DEFAULT);
	uv_loop_close(uv_default_loop());
	destroy_uv_idle_t(idler)

func wait
	counter++
	if counter >= 100000
		uv_idle_stop(idler)
	ok

