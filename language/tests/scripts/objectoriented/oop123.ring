# Test using return inside braces inside func. para
test()

func test
	o = new myclass
for t=1 to 10
	? :before
	try
		mytest( o { return } )
	catch
		? cCatchError
	done
	? :after
next

func mytest para

class myclass