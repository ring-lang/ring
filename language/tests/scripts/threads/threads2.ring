Load "gamelib.ring"

o1 = new mythreads

func al_rest2 nTime
	for v=1 to 5000
	next

Func Main
        al_init()
        for k = 1 to 10
                al_create_thread("o1.thread1()")
                al_create_thread("o1.thread2()")
                al_create_thread("o1.thread3()")
        next
        al_rest(5)
	? :Done

Class Mythreads

        cAppName = "Threads Application"

        Func Thread1
                for x = 1 to 50
                        see x + nl
			al_rest2(0.01)
                next
                See 'Thread(1) : Application Name : '  + cAppName + nl

        Func Thread2
                for x = 1 to 50
                        see '*****' + x + nl
			al_rest2(0.01)
                next
                See 'Thread(2) : Application Name : '  + cAppName + nl

        Func Thread3
                for x = 1 to 50
                        see '!!!!' + x + nl
			al_rest2(0.01)
                next
                See 'Thread(3) : Application Name : '  + cAppName + nl
