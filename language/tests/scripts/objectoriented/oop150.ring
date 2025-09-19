o1 = new Point1

o1.x += 10

? o1.x

? copy("=",20)

o2 = new Point2

o2.x += 10

? o2.x

class Point1

	x=10 y=10

	func getx
		? "Getter"
		return x
class Point2

	x=10 y=10 

	func setx v
		? "Setter"
		? "v = " + v
		x = v

