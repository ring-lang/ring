myobj = new Start
myobj.one()
myobj.one().two()
myobj.one().two().three()
myobj.one().two().three().go()
? copy("*",10)
myobj	.one()
	.two()
	.three()
	.go()
? copy("*",10)
myobj {
	one()
	.two()
	.three()
	.go()
}

class start
	func one
		? "One"
		return new one


class one 

	func two
		? "Two"
		return new two

class two

	func three
		? "Three"
		return new three

class three

	func go
		? "Go!"