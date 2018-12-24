new first { test() }

Class first
	myvalue = 10
	func test
		o1 = new second
		o1.test2(myvalue)	
	
class second
	num1 = 10
	num2 = 20
	func test2 x	
		see "test2" + nl +
		    "para : " + x + nl
		