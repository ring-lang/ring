mylist = [1,2,3]
mytest() + 10
? mylist
mytest() = [4,5,6]
? mylist
myobj = new point { x=10 y=20 z=30 }
? myobj
mytest2() { x=100 y=200 z=300 }
? myobj
mytest2() = new point { x=1000 y=2000 z=3000 }
? myobj
func mytest
	return mylist
func mytest2
	return myobj
class point x y z