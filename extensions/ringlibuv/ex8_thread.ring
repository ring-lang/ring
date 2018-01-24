load "libuv.ring"
load "objectslib.ring"

? "Testing RingLibUV - Threads - Using Classes"

open_object(:MyThreads)

class MyThreads from ObjectControllerParent

	func Start

	    tracklen = 10
	    hare_id = new_uv_thread_t()
	    tortoise_id = new_uv_thread_t()
	    uv_thread_create(hare_id, method(:one))
	    uv_thread_create(tortoise_id, Method(:Two))
	
	    uv_thread_join(hare_id)
	    uv_thread_join(tortoise_id)
	
	func one
		? "Message from the First Thread!"
	
	func Two
		? "Message from the Second Thread!"
	
    
