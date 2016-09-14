	new point { test() }

	class point
		x=10 y=20
		func test
			see x + nl + y + nl # works fine
			myobj = new otherclass {
				see name + nl
				see x + nl + y + nl # error !
			}

	class otherclass
		name = "test"