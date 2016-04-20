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
			see "test : " + test + nl
		}
	}

func tocall f1,p1,p2
	see "in tocall" + nl
	call f1(p1,p2)
	see "try inside!" + nl
				if p2 = KEY_SPACE
					obase {
						point {
							see "before file" + nl
							file = "test.jpg"
							see "after file" + nl
						}	
					}
				ok


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
		see "welcome" + nl
		if lbraceend = true and test != ""
			see "Wow" + nl
			lbraceend = false
			see "test : " + test + nl
			see "before call" + nl
			#call test(self,1)				
			tocall(test,self,1)
			see "after call" + nl
		ok