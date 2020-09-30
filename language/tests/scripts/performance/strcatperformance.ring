t1 = clock()
test = "Number "
for x = 1 to 20000
	test += x
next 
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"
