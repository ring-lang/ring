func main
	o1 = new program {
		test()
	}
	? o1

class program 
	this.name = "My Application"
	this.version = "1.0"
	? name ? version	

	func test
		? "Name    = " + name 
		? "Version = " + version