? "Using * operator"
t1 = clock()
for x = 1 to 1000000
	out = x * 2
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

? "Using *= operator"
t1 = clock()
for x = 1 to 1000000
	out = x
	out *= 2
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"
