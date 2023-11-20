load "threads.ring"

func main

	nThreads = 2
	aList = list(nThreads)

	for x=1 to nThreads
		aList[x] = new_thrd_t()
		thrd_create(aList[x],"Hello("+x+")")
	next

	for x=1 to nThreads
		res= 0
		thrd_join(aList[x],:res)
	next

	? :Done

func Hello x

	for r=1 to 100
		? "Message from the Hello("+x+") function"
	next
