new test {main()}

class test
	nID = 0
	aObjects = []

	func main
		mypoint = new point {x=10 y=20 z=30}
		add(mypoint)

	func add oObject
		aObjects + oObject
		nID++
		oObject.nIndex = nID
		see oObject

class base
	nIndex
class point from base x y z
