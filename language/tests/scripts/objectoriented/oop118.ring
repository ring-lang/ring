o1 = new class1
o2 = new class2

o1 + o2
o2 + o1


class class1

	func operator cOp, vValue
		? "Hello from class1 operator() method"

class class2

	func operator cOp, vValue
		? "Hello from class2 operator() method"
	