C_COUNT = 1_000_000

? "Using * operator"
t1 = clock()
out = 10
for x = 1 to C_COUNT
	out = out * 2
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

? "Using *= operator"
t1 = clock()
for x = 1 to C_COUNT
	out *= 2
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"
