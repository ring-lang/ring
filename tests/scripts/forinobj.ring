func main
	new test { go() }

class base
	nice = 1

class test from base
	func go
		aObjects = []
		for t = 1 to 10
			aObjects + new point {x=10 y=20 z=30}
		next

		#see aObjects


		myobj = new myclass

		for v = 1 to 100
			for t in aObjects t.great(nice) next
			see aObjects
			for r in aObjects r.great("gogd") next
		next

	func getnice
		see "great" + nl


class point x y z
	func great r
		see "Wow" + nl

class myclass
	func show x
		see "Welcome" + nl