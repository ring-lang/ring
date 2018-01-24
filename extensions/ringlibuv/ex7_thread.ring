load "libuv.ring"

? "Testing RingLibUV - Threads"

func main
    tracklen = 10
    hare_id = new_uv_thread_t()
    tortoise_id = new_uv_thread_t()
    uv_thread_create(hare_id, "hare()")
    uv_thread_create(tortoise_id, "tortoise()")

    uv_thread_join(hare_id)
    uv_thread_join(tortoise_id)

func hare
	? "Message from the Hare function!"

func tortoise
	? "Message from the Tortoise function!"

    
