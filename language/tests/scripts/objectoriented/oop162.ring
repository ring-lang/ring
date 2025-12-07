# Using (ON, OFF, CASE) keywords as identifiers (variables/attributes)

func main

	on   = 1
	off  = 0
	case = 10
	? on
	? off
	? case
	? copy("*",20)

	nValue = 1
	switch nValue
	on 1 ? "one"
	on 2 ? "two"
	off
	? copy("*",20)

	test()

func test
	new mytest { ON OFF CASE ? self ? methods(self) }
	? copy("*",20)

class mytest

	ON OFF CASE

	func geton
		? "getON()"

	func getOFF
		? "getOFF()"

	func getCASE
		? "getCASE()"

