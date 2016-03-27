Load "gamelib.ring"

cAppName = "Threads Application!"

o1 = new mythreads 

Func Main
	al_init()
	see "first thread!" + nl
	al_create_thread("o1.thread1()")
	see "second thread!" + nl
	al_create_thread("o1.thread2()")
	see "third thread!" + nl
	al_create_thread("o1.thread3()")
	see "forth thread!" + nl
	for k = 1 to 5
	al_create_thread("
		for r = 1 to 5
			see r + nl	
		next
		See 'Thread(4) : Application Name : '  + cAppName + nl
	")
	al_rest(5)
next

Class Mythreads

	cAppName = "Threads Application"

	func thread1
		for x = 1 to 5
			see x + nl	
		next
		See 'Thread(1) : Application Name : '  + cAppName + nl

	func thread2
		for x = 1 to 5
			see '*****' + x + nl	
		next
 		See 'Thread(2) : Application Name : '  + cAppName + nl

	func thread3
		for x = 1 to 5
			see '!!!!' + x + nl	
		next
 		See 'Thread(3) : Application Name : '  + cAppName + nl