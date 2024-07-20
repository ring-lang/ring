/*
** Ring is a very dynamic language
** The scope of the variable could be changed during runtime
*/

o1 = new point
test(o1)	# At first x will be a local variable
test(o1)	# Now x is an attribute (not local)

func test o1
	o1 {
		x = 10
		for t=1 to 10
			if t = 5
				if ! isAttribute(self,:x)
					addAttribute(self,:x)
				ok
				self.x = 100
			ok
			? x
		next
		? x
		? self.x
		? "************"
	}

class point 