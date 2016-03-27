o1 = new parent { print() }

func test cText
	see "Text : " + cText + nl

Class Parent
	y = 20
	func print
		test(y)
		test(x) # here is the bug, passing private attribute as parameter

	func nice cText
		see "Wow Text : " + cText + nl

	private
		x = 10

