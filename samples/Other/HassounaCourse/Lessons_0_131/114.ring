
c1 = new class1
c1.func1()

c2 = new class2
c2.func1()

c3 = new class3
c3.func1()

class class3 from class2{
	func func1{
		see "Class3>>Func1"
	}
}

class class2 from class1{
	func func1{
		see "Class2>>Func1" + nl
	}
}

class class1{
	func func1{
		see "Class1>>Func1" + nl
	}
}
