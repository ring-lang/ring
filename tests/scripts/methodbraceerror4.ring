new point { test() }

	class point
		x=10 y=20
		func test
			oSelf = self
			see x + nl + y + nl  
			myobj = new otherclass {
				see name + nl
				oSelf {
					see x + nl + y + nl
				}
			}

	class otherclass
		name = "test"
