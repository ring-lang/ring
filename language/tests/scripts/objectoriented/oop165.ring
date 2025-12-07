# Using the AGAIN keyword as identifier (variables/attributes)

func main

	Again = :test
	? Again

	x=10
	do
		? x
		x--
	again x > 0

	test()

func test
	new mytest { Again ? self ? methods(self) }
	? copy("*",20)

	new mytest {
			I will say it again an again
			YOU ARE MY LOVE
	}
	? copy("*",20)


class mytest

	Again

	func getAgain
		? "getAgain()"

	func braceError

	