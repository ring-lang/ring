# Change (Self, This & Super) - Useful for translation to Arabic language

new point { x=10 y=20 z=30 ? self }

ChangeRingKeyword self my

new point { x=10 y=20 z=30 ? my }

# Since self is an identifier (not a real keyword)
# We can use (self) or (my) at the same time
# This is useful for code that already uses (self)
# Where we can translate (self) to Arabic keyword

new point { x=100 y=200 z=300 ? my ? self }

new point { x=1000 y=2000 z=3000 test()}

class parent 

	func test 

		? "Parent - Test()"

class point from parent 

	x y z 

	func test

		ChangeRingKeyword this mypoint

		? this
		? mypoint
	
		ChangeRingKeyword super father

		super.test()

		father.test()