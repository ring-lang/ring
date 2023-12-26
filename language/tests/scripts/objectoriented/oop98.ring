new Child { test() }
new Alone { test() }

class Parent
class Child from Parent
	func test
		? "Parent: " + parentClassName(self)

class Alone
	func test
		? "Parent: " + parentClassName(self)