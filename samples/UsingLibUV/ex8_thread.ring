load "libuv.ring"
load "objectslib.ring"

? "Testing RingLibuv - Threads - Using Classes"

open_object(:MyThreads)

class MyThreads from ObjectControllerParent

	func Start
		one_id = new_uv_thread_t()
		two_id = new_uv_thread_t()
		uv_thread_create(one_id, Method(:One))
		uv_thread_create(two_id, Method(:Two))
		uv_thread_join(one_id)
		uv_thread_join(two_id)
		destroy_uv_thread_t(one_id)
		destroy_uv_thread_t(two_id)
	
	func one
		? "Message from the First Thread!"
	
	func Two
		? "Message from the Second Thread!"
	
    
