load "threads.ring"

func main

	nThreads = 10
	aList = list(nThreads)

	for x=1 to nThreads
		aList[x] = new_thrd_t()
		thrd_create(aList[x],"Hello("+x+")")
	next

	for k=1 to nThreads
		 ? "*** Before join: " + k + " *** "
		 res = 0
		 thrd_join(aList[K],:res)
		 ? "*** After join: " + k + " *** "
	next

	? " ===== Done ========== "

func Hello x

	for r=1 to 100
		? "("+r+") Message from the Hello("+x+") function"
	next