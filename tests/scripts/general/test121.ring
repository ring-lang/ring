x = "welcome"
p1 = varptr("x","char")
? type(p1)
test()

func test
	y = "Hello"
	p2 = varptr(:y,:char)
	? type(p2)