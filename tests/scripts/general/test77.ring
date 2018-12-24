func main
	o1 = new myclass { test() test2() }
	test2()

func f1
	see "f1 function" + nl

func f2 
	see "f2 function" + nl

func f3 
	see "f3 function" + nl

func test2
	myline()
	see "test2 function" + nl
	new myclass {
		f1()
		f2()
		f3()
		self.f3()
	}	
	myobj = new myclass
	myobj.f3()
	myline()

func myline
	see copy("=",40) + nl

Class myclass

	func test
		myline()
		see "test method" + nl
		f1()
		f2()
		f3()
		myline()

	func f3
		see "f3 method" + nl

	func test2
		myline()
		see "test2 method" + nl
		self {
			f1()
			f2()
			f3()
		}
		myline()
