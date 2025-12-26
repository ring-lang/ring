x=10 y=20 z=30

myobj  = new myclass
myobj2 = new myclass

test(myobj)

addattribute(myobj,[:x,:y,:z])

myobj.x=100
myobj.y=200
myobj.z=300
? myobj

test(myobj)
test(myobj2)
test(myobj)
test(myobj2)


func test oObj

	# x,y,z could be global variables or attributes!

	oObj {
		? x		
		? y
		? z
	}


class myclass