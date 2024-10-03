test1()

func test1
	? :test1
	test2()

func test2
	? :test2
	test3(0,0,0)

func test3 p1,p2,p3

	? :test3	
	aCall = ringvm_calllist()
	? "This function (test3) is called from line: " + aCall[len(aCall)-1][7]
	? "This function (test3) need parameters: " + aCall[len(aCall)-1][8]
	? :done