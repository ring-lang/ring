C_COUNT = 1_000_000

? "Create the list using the Range operator"
t1 = clock()
aList = 1:C_COUNT
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

? "Create the list using the For loop"
t1 = clock()
aList = []
for x = 1 to C_COUNT
	aList + x
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

? "Create the list using the list() function and the For loop"
t1 = clock()
aList = list(C_COUNT)
for x = 1 to C_COUNT
	aList[x] = x
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"
