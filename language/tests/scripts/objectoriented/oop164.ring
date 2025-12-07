# Using (But, Ok) keywords as identifiers (variables/attributes)

func main

	But     = 1
	Ok      = 2
	? But
	? Ok

	var = 1
	if var=1
		? :one
	but var=2
		? :two
	else
		? :three
	ok
	? copy("*",20)

	test()

func test
	new mytest { But Ok ? self ? methods(self) }
	? copy("*",20)

	new mytest {
			Start
			I love Programming but I love Ring Programming More 
			Ok, Ring is really fun 
			Window title is "GREAT"
			Window title to myvar
			Done
	}
	? copy("*",20)


class mytest

	But Ok

	func getBut
		? "getBut()"

	func getOk
		? "getOk()"

	func braceError

	