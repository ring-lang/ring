# Test using return inside braces inside func. para
test()

func test
	o = new myclass
	? :before
	try
		mytest( o { return } )
	catch
		? cCatchError
	done
	? :after

func mytest para

class myclass