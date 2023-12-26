new child  { test() }

class parent
	func good
		? :good

class child from parent
	func test
		? "Parent: " + parentclassname(self)
		super.good()
		try
			super = NULL
		catch
			? "We can't delete the Super"
		done
		? super.good()