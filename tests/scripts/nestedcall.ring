o1 = new test
o1.f1().f2()
see o1.count?() + nl

class test 
	func f1
		see "F1" + nl
		return self
	func f2
		see "F2" + nl
	func count?
		return len(methods(self))
	