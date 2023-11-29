# This is a complex test for passing variable pointer through a variable name
# Here we pass an attribute name from a method

? "Loading Library"
loadlib("mylib.dll")

func main
	o = new myclass { goo() }
	? o.cstring

class myclass

	cString = space(100)

	func goo
		test(test(test(changevalue(:cString))))
		? cString

func test v