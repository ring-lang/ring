# When init() return a different object
# dot/braces after init() works on that different object
# after init() the different object is removed from stack
# if we called a method on the different object we get the method output
# if no method is called we get the original object after init() output is removed from stack
# Note: Ring supports using lists/objects during definition which requires this

? new point		# 10 20 30
? new point()		# 10 20 30 (we have new point and init() output is ignored)
			# Remember in many programs init() doesn't include Return
			# i.e. in many programs init() output is an empty string

new point().test()	# 100 200 300 (test() uses init() output)
? new point().test()	# 100 200 300 nice (? uses test() output)

aList = []
aList + new point2 {x=100 y=200 z=300}
aList + new point2()	# init() return empty string but the object is added to the list

? aList

class point 

	x=10 y=20 z=30
	
	func init
		o = new point { x=100 y=200 z=300 }
		return o

	func test
		? "Hello from test() method"
		? self
		return "nice"

class point2

	
	x y z
	
	func init
		x=10
		y=20
		z=30
		# No return is used
