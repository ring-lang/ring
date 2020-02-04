
//see clock()

/*
for x=1 to 1000
	see clock()
next
*/


//see clockspersecond()


t1 = clock()

for x=1 to 10000
	see x
next

t2 = clock() - t1

see nl + "===========" + nl
see t2

see nl + "===========" + nl
see t2 / clockspersecond()
see " Sec"

