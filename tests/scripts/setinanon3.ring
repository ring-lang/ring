obase = new mybase
KEY_SPACE = 1

func main
	obase {
		point {
			test = func oself,nkey {
				if nKey = KEY_SPACE
					obase {
						point {
							file = "test.jpg"
						}	
					}
				ok
			}
		}
	}

call test("tt",1)

class mybase
	point lbraceend  = true
	func getpoint
		return new point
	func braceend
		if lbraceend = true
			lbraceend = false
						
		ok

class point 
	x y z file
	func setfile t
		see "wow" + nl
		x = t