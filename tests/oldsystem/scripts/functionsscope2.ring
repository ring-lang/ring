func main
	o1 = new myclass { test()}

func f1
	see "f1 function" + nl

func f2 
	see "f2 function" + nl

func f3 
	see "f3 function" + nl

func myline
	see copy("=",40) + nl

Class myclass

	func test
		myline()
		see "test method" + nl
		f1()
		f2()
		f3()		   # call f3() method	
		new local { f3() } # call f3() function 
		myline()

	func f3
		see "f3 method" + nl

class local