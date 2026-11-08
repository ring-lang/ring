oOther = NULL

func main

	? "Start"

	title("new Class { } then .attribute")
	? new Point { x = 3 }.x
	? new Point { x = 3 }.calc()
	? new Point { x = 3 }.me().x
	y = new Point { x = 3 }.x
	? y
	? 1 + new Point { x = 3 }.x
	? new Point { x = 3 }.x + 1
	aList = [new Point { x = 5 }.x, new Point { x = 6 }.calc()]
	? aList
	? new Point { aItems = [7, 8] }.aItems[2]
	? len(new Point { aItems = [1, 2, 3] }.aItems)

	title("new Class(args) then .attribute or .method()")
	? new Point(4).x
	? new Point(4).calc()
	? new Point(4).me().calc()
	? new Point(4).me().x + 1
	y = new Point(9).x
	? y
	? f(new Point(4).x)
	? [new Point(1).x, new Point(2).calc()]
	? new Point(4).aItems[1]

	title("Assignment forms")
	n = 10
	n += new Point { x = 3 }.x
	n += new Point(4).x
	? n
	o = new Point { x = 2 }
	o.x = new Point(5).calc()
	? o.x

	title("The result is the new object")
	o = new Point
	? o.x
	o = new Point { x = 1 }
	? o.x
	o = new Point(2)
	? o.x
	o = new Point(2) { x = x + 1 }
	? o.x
	o = new Point(3)
	{
		? "a brace on the next line: " + x
	}
	? o.x
	cClass = "Point"
	o = new from cClass
	? classname(o)
	? classname(new Point(4))
	? classname(new Point(4).me())

	title("Arguments of init(): calls and dots inside them")
	oP = new Point { x = 7 }
	o = new Holder(oP)
	? o.v.x
	o = new Holder(f(5))
	? o.v
	o = new Holder(new Point(8).x)
	? o.v
	o = new Holder(getPoint().x)
	? o.v
	o = new Holder(func n { return n * 3 })
	fAnon = o.v
	? call fAnon(2)

	title("Inside functions, methods and braces")
	? fromFunc()
	p = new Point { x = 20 }
	? p.other()
	p {
		? new Point(30).x + x
	}

	title("init() that doesn't return self: new Class(args) { } is error")
	try
		? new NoSelf(4).x
	catch
		? cCatchError
	done
	try
		? new NoSelf(4).calc()
	catch
		? cCatchError
	done
	try
		o = new NoSelf(4) { x = 1 }
	catch
		? cCatchError
	done

	title("new Class(args) { } then .attribute or .method()")
	? new Point(4) { x = 5 }.x
	? new Point(4) { x = 5 }.calc()
	? new Point(4) { x += 1 }.me().calc() + 1
	y = new Point(4) { x = 6 }.x
	? y
	? [new Point(1) { x = 2 }.x, new Point(1) { x = 3 }.calc()]
	? new Point(4) { aItems + 9 }.aItems[3]
	o = new Point(4) { x = 7 }
	? o.x
	# The braces work on the object returned by init(), the result is the new object
	? classname(new Other() { ? "braces on: " + classname(self) })
	try
		? new Other() { x = 50 }.nValue
	catch
		? cCatchError
	done
	? "other object: " + oOther.x

	? "Done"

func title cTitle
	
	? copy("=",70)
	? cTitle
	? copy("=",70)
	

func f n

	return n * 2

func getPoint

	return new Point(6)

func fromFunc

	return new Point(11).x + new Point { x = 1 }.x

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

class NoSelf

	x = 0

	func init n

		x = n

	func calc

		return x * 2
