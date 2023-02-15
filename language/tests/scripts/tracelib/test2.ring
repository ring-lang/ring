load "tracelib.ring"

# Trace control flow between functions
Trace(:Functions)

test1()

func test1
	see :test1 + nl
	test2()

func test2
	see :test2 + nl
	see test3() + nl

func test3
	see :test3 + nl
	return "test 3 output" 
	
