load "libuv.ring"

? "Testing RingLibuv - Threads"

func main
	one_id = new_uv_thread_t()
	two_id = new_uv_thread_t()
	uv_thread_create(one_id, "one()")
	uv_thread_create(two_id, "two()")
	uv_thread_join(one_id)
	uv_thread_join(two_id)
	destroy_uv_thread_t(one_id)
	destroy_uv_thread_t(two_id)

func one
	? "Message from the First Thread!"

func two
	? "Message from the Second Thread!"

    
