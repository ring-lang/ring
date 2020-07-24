Load "gamelib.ring"

o1 = new mythreads

Func Main
        al_init()
        for k = 1 to 5
                al_create_thread("o1.thread1()")
                al_create_thread("o1.thread2()")
                al_create_thread("o1.thread3()")
        next
        al_rest(30)

Class Mythreads

        cAppName = "Threads Application"

        Func Thread1
                for x = 1 to 50
                        see x + nl
			al_rest(0.1)
                next
                See 'Thread(1) : Application Name : '  + cAppName + nl

        Func Thread2
                for x = 1 to 50
                        see '*****' + x + nl
			al_rest(0.1)
                next
                See 'Thread(2) : Application Name : '  + cAppName + nl

        Func Thread3
                for x = 1 to 50
                        see '!!!!' + x + nl
			al_rest(0.1)
                next
                See 'Thread(3) : Application Name : '  + cAppName + nl
