func main

? new point { x=10 y=20 z=30 }.test()
? "========"
o1 = new point { x=10 y=20 z=30 }
? o1 { }.test()
? "========"
? new point2 { x=10 y=20 z=30 }.test2()
? "========"
? new point3() { ? :before ? self ? :after }
? "========"

myobj = new point3() 
? myobj
? myobj { ? :before2 ? self ? :after2 }

? "========"

? new point3() { ? :before3 ? self ? :after3 }.nice().happy()

? "========"

? myobj.nice().happy()
? "========"

? myobj {}.nice().happy()
? "========"
? myobj { ? :before4 ? self ? :after4 }.nice().happy()
? "========"

? new point3 { ? :before5 ? self ? :after5 }.nice().happy()


class point 

	x y z

	func test 
		? :test
		return :wow

class point2

	x y z

	func braceEnd
		? :braceEnd2
		return :good

	func test2 
		? :test2
		return :wow2

class point3

	x y z

	func init 
		self.x = 1000
		self.y = 2000
		self.z = 3000
		return self

	func braceEnd
		? :braceEnd3
		x = 10000
		y = 20000
		z = 30000
		return :great

	func test3 
		? :test3
		? "x = " + x
		? "y = " + y
		? "z = " + z
		return :wow3

	func nice
		y = 50000
		? "nice and good"
		return self

	func happy
		? :happy
		return "What"