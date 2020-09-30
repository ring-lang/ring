Load "gamelib.ring"

newline = ""

o1 = new mythreads

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
                        see x + newline
			al_rest(0.01)
                next
                See 'Thread(1) : Application Name : '  + cAppName + newline

        Func Thread2
                for x = 1 to 50
                        see '*****' + x + newline
			al_rest(0.01)
                next
                See 'Thread(2) : Application Name : '  + cAppName + newline

        Func Thread3
                for x = 1 to 50
                        see '!!!!' + x + newline
			al_rest(0.01)
                next
                See 'Thread(3) : Application Name : '  + cAppName + newline
