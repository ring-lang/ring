load "tests\errorcall2.nova"
# 1 / 0
# func main
great()

func one
	see "one"
	two()

func two
	see "two"
	o = new Person
	o.print()

func three
	see "three"
	x = 1 / 0

class person
	func print
		three()