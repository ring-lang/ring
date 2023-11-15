for t=1 to 10
	myfunc(t).test()
	myfunc(t) { test() }
	eval("return myfunc(t)").test()
	eval("return myfunc(t)") { test() }
next

func myfunc t
	if t % 2 = 1
		return new myclass1
	ok
	return new myclass2

class myclass1
	func test
		? "hello from myclass1"

class myclass2
	func test
		? "hello from myclass2"