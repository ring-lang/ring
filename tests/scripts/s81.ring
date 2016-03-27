x = test2() 
see x

see "welcome "
for x = 1 to 10
	myfirst(3,x)
	see nl
next

mysecond("Mahmoud")
#mysecond(5,6)
#mysecond(5)

mylist = [1,2,3,4,5,6,7,8,9,10,["one","two"]]

len(mylist[11])
see nl
len(mylist)
y = myfirst()
see y

see "The list size is " + len(mylist) + nl
see "The sublist size is " + len(mylist[11]) + nl

see " List reverse" + nl
see reverse(mylist)

see "print list " + nl

for x = 1 to len(mylist)
	see mylist[x]
	see nl
next

func test
	see "nice " + nl

func test2
	return