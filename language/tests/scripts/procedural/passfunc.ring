test(:one)
test(:two)
test(:three)
myobj = new myclass
test2(myobj,:mymethod)

func one
	? "Hello from one() function"

func two
	? "Hello from two() function"

func three 
	? "Hello from three() function"

func test cPara
	call cPara()

func test2 oObj,cPara
	oObj {
		call cPara()
	}

class myclass
	func mymethod
		? "Hello from mymethod()"