p1 = new Point
p1.x = 10 p1.y = 20 p1.z = 30
p1.print()

o1 = new SayHello
o1.name = "Mahmoud"
o1.say()

Class Point
	x y z
	func print
		see "x : " + x + nl +
		    "y : " + y + nl +
		    "z : " + z + nl

Class SayHello
	Name
	Func Say
		see "Hello " + Name + nl
