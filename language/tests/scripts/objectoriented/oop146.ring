o1 = new test

for t=1 to 5
	o1.x++
next

for t=1 to 5
	o1 {
		x++
	}
next

class test 

	x = new myclass 
 
	func getx 
		? :getter
		return x

	func setx obj
		? :setter
		? "value: " + obj.value + nl
		x = obj

class myclass

	value = 1000

	func operator cOp, vValue
		? "Operator Overloading" 
		? "Operator: " + cOP
		value++
		return self