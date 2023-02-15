load "tracelib.ring"

# Pass Error
Trace(:PassError)

test1()

func test1
	x = 10
	see :test1 + nl
	test2()	# Runtime Error!
	see "We can continue!"
