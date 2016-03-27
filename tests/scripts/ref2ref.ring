new point { 
	x=10 y=20 z=30
	print() 
} 

func test oObject
	see "Welcome" + nl
	r = '
	see oObject.x + nl
	see oObject.y + nl
	see oObject.mybook.title + nl
	see oObject.mybook.content + nl
	'
	eval(r)

	t = '
	see mybook.title + nl
	see mybook.content + nl
	'
	oObject {
	eval(t)
	}


Class point 
	x y z 
	mybook = new book { title = "programming" content = "Great" }

	func print 
		see x + nl + y + nl + z + nl
		good = self
		new page {
		TEST(good)
		}

class book title content

class page address 