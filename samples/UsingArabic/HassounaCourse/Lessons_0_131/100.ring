
L1 = new line{
	name = "Line1"
	color = "Red"
	p1{  x=50   y=10  }
	p2{  x=150 y=30 }
	printInfo()
}

see "=================" + nl

L2 = new line{
	name = "Line2"
	color = "Navy"
	p1{ x=20   y=60 }
	p2{ x=120 y=180}
	printInfo()
}

class line
	name
	color
	p1 = new point
	p2 = new point

	func printInfo
		see "Name  : "  + name + nl
		see "Color   : "  + color + nl
		see "Point 1: "  + "( X=" + p1.x + " ; Y=" + p1.y + " )" + nl
		see "Point 2: "  + "( X=" + p2.x + " ; Y=" + p2.y + " )" + nl
	end

end

class point x y

/*
see "Name  : "  + L1.name + nl
see "Color   : "  + L1.color + nl
see "Point 1: "  + "( X=" + L1.p1.x + " ; Y=" + L1.p1.y + " )" + nl
see "Point 2: "  + "( X=" + L1.p2.x + " ; Y=" + L1.p2.y + " )" + nl
*/
