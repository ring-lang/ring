? "Create the list using the Range operator"
t1 = clock()
aList = 1:1000000
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

? "Create the list using the For loop"
t1 = clock()
aList = []
for x = 1 to 1000000
	aList + x
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

? "Create the list using the list() function and the For loop"
t1 = clock()
aList = list(1000000)
for x = 1 to 1000000
	aList[x] = x
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"