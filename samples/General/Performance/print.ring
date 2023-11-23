t1=clock()
for t=1 to 400_000
	? t
next
? "Time: " + (clock()-t1)/clockspersecond()
