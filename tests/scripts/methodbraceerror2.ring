	new point { test() }

	class point
		x=10 y=20
		func test
			see x + nl + y + nl # works fine
			myobj = new otherclass 
			see myobj.name + nl
			see x + nl + y + nl 

	class otherclass
		name = "test"