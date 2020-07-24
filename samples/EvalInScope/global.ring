test() 
test2()
? "Print x = " + x

func test
	global(:x)
	x = 10
	? "Print x from test() = " + x

func test2
	? "Print x from test2() = " + x

func global cVar
	ringvm_EvalInScope(1, cVar + " = NULL ")