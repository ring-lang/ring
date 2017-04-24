obj = new myevent 
obj.test()

class mytest 
	func braceerror
		see :braceerror + nl

class myevent

	func test
		o = new mytest 
		SEE "BEFORE o.what() " +nl 
		o.what() 
		see "done" + nl
