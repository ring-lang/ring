load "tracelib.ring"
Trace(:LineByLine)

test1()

func test1
	x = 10
	see :test1 + nl
	t = 12
	test2()
	see "After Error!" +nl
	see "t = " + t + nl
	
