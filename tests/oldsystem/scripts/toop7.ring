o1 = new point { x = 10 y = 10 print("P1    : ") }
o2 = new point { x = 20 y = 40 print("P2    : ") }

o3 = o1 + o2
o3.print("P1+P2 : ")

class point x y

	func operator cOperator,Para
		result = new point	
		switch cOperator
		on "+"
			result.x = x + Para.x
			result.y = y + Para.y
		on "-"
			result.x = x - Para.x
			result.y = y - Para.y
		off
		return result

	func print cPoint
		see cPoint + "X : " + x + " Y : " + y + nl