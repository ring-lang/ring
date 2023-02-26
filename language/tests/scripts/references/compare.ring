aList  = [1,2,3,4,5]
aList2 = ref(aList)
? aList=aList2
test(aList)
v = test2(aList)
? v = aList
v = test3(aList)
? v = aList

aStore = [ aList ]

v = test4( aStore[1] )
? v = aList
v = test5()
? v = aList

func test mylist 
	? mylist=aList

func test2 mylist
	return mylist

func test3 mylist
	return ref(mylist)

func test4 mylist
	return mylist

func test5 
	return aStore[1]