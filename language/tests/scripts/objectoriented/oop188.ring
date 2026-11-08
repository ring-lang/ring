oOther = NULL
oSeen = NULL

func main

	? "Start"

	new Replaced().test()
	? new Replaced().x + new Replaced() { z = 1 }.z

	oSeen = new Seen(5)
	? oSeen.v
	oA = new Point(4)
	? oA.x + oA.calc()

	oB = new Replaced()
	? classname(oB) + " " + oB.x
	oC = new Replaced() { z = 2 }
	? "" + oC.x + " " + oC.z
	for n = 1 to 3
		oL = new Point(n)
		see "" + oL.x + " "
	next
	? ""
	try
		oD = new NoInitClass(1)
	catch
		? "no init: " + (substr(cCatchError, "init") > 0)
	done

	oH = new Holder(new Point { x = 7 })
	? oH.v.x
	? new Holder(new Point { x = 8 }).v.x

	oBox = new Box
	oBox {
		oH = new Holder(nValue)
		? oH.v
		? new Holder(nValue + 1).v
	}

	oP = new Point(1)
	oP.init(2)
	? oP.x

	? "Done"

class Point
	x = 0
	aItems = []
	func init n
		x = n
		aItems = [n, n + 1]
		return self
	func calc
		return x * 2
	func me
		return self
	func other
		return new Point(x + 1).calc()

class Holder
	v
	func init value
		v = value
		return self

class Other
	nValue = 0
	func init
		oOther = new Point(100)
		return oOther

class Seen
	v = 0
	func init n
		v = n
		? "in init, oSeen.v = " + oSeen.v
		return self

class Box
	nValue = 99

class NoInitClass
	x = 0

class Replaced
	x = 10 y = 20 z = 30
	func init
		o = new Replaced { x = 100 y = 200 z = 300 }
		return o
	func test
		? self
