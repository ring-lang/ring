mylist = [ 1:10 ]
? :before
test(ref(mylist[1]))
? :after

func test x
	? refcount(x)
	ref(test2(ref(x)))
	? refcount(x)

func test2 x
	? refcount(x)
	mylist = null
	? refcount(x)
	return x