t1 = clock()
for x = 1 to 10000
	see "test"
next
? "Time " + ((clock()-t1)/clockspersecond()) + " seconds"