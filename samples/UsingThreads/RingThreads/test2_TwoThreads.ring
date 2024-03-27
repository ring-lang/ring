load "threads.ring"

func main

	t = new_thrd_t()
	thrd_create(t,"Hello()")
	res = 0
	thrd_join(t, :res)

	t2 = new_thrd_t()
	thrd_create(t2,"Hello2()")
	res2 = 0
	thrd_join(t2, :res2)

	? :done

func Hello

	? "Message from the Hello() function"

func Hello2

	? "Message from the Hello2() function"