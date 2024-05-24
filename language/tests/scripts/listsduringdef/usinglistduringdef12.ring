myobj = new good {
	x = new test + [1,2,3,new point]
}

? myobj

myobj = new good {
	# You may think that we can use list during defintion and x[4] is an object (new point)
	# BUT WE HAVE A SETTER WHICH MUST BE CALLED SO X IS NOT A LIST
	# In reality x will be (NULL) so using X[1] ... X[4] will get the NULL string letters!
	x = [1,2,3,new point,x[1],x[2],x[3],x[4]]
}

? myobj.x


class good
	x
	y 

	func setX value
		? :setter
		x = value
		y = :nice

class test
	v = "test"

	func operator cOp, vVal
		v = v + type(vVal)
		return self

class point
	x=10 y=20 z=30