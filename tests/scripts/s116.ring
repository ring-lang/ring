t1 = clock()
aList = 1:100000
for x in aList
	#see "Item : " + x + nl
next
see "Time : " + (clock() - t1)
