func main
	aList = [5,4,3,2,1]
	x = ref( sort(aList) )
	? refcount(x)
	x = ref(test())
	? refcount(x)
	x = ref(test2())
	? refcount(x)	
	x = test3()
	? refcount(x)
func test
	aList = [5,4,3,2,1]
	return sort(aList)

func test2
	aList = [5,4,3,2,1]
	return aList

func test3
	aList = [1,2,3,4,5]
	return ref(aList)