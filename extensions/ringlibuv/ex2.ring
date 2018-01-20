load "libuv.ring"

counter = 0
idler = NULL 

func main
	idler = uv_new_uv_idle_t()
	uv_idle_init(uv_default_loop(), idler)
	wait_for_a_while = uv_callback(idler,"idle","wait()")
	uv_idle_start(idler, wait_for_a_while)
	? "Idling..."
	uv_run(uv_default_loop(), UV_RUN_DEFAULT);
	uv_loop_close(uv_default_loop());

func wait
	counter++
	if counter >= 100000
		uv_idle_stop(idler)
	ok
