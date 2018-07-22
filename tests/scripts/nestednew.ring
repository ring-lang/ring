# Testing nested new commands and the pVM->pAssignment flag

o1 = new parent() {
	new child(o1) {
		test()
	}
	test()
}

class parent

	func init 
		return self

	func test
		? "hello from parent"

class child

	func init oParent
		if classname(oParent) = :parent
			? "True parent!"
		else 
			raise("Bad parent!")
		ok
		return self 

	func test
		? "hello from child"