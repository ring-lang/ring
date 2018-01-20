load "libuv.ring"

func main

	myloop = uv_new_uv_loop_t()
	uv_loop_init(myloop)
	? "Now quitting"
	uv_run(myloop, UV_RUN_DEFAULT)
	uv_loop_close(myloop)
	uv_destroy_uv_loop_t(myloop)
