? "Start"
? great()
? "End"

func great
	new mytest { return test() }

class mytest
	func test 
		? "Message From Test"
		return "Test Output"