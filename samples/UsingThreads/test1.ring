load "threads.ring"

func main

	t = new_thrd_t()
	thrd_create(t,"Hello()")
	res = 0
	thrd_join(t, :res)

func Hello

	? "Message from the Hello() function"