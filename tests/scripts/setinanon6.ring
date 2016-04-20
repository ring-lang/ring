obase = new mybase
KEY_SPACE = 1

func main
	obase {
		point {
			test = func oself,nkey {
				if nKey = KEY_SPACE
					obase {
						point {
							see "before file" + nl
							file = "test.jpg"
							see "after file" + nl
						}	
					}
				ok
			}
		}
	}


class mybase
	point 
	func getpoint
		return new point

class point 
	x y z file test=""  lbraceend  = true
	func setfile t
		see "setfile : wow" + nl
		x = t

	func braceend
		if lbraceend = true and test != ""
			lbraceend = false
			call test(self,1)				
		ok