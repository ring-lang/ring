see "hello world" + nl
mylist = []
for x = 1 to 100000
	add(mylist,x)
next
nSum = 0
for x = 1 to 100000
	nSum = nSum + mylist[x] 
next
see nSum
see nl
