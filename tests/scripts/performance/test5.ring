t1 = clock()
for x = 1 to 20000
	myfunc(x)
next
see "Time : " + (( clock() - t1 )/ clockspersecond() ) + nl

func myfunc x
	x++