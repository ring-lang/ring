new point    { ? self }
new point2() { ? self }
new point3() { ? self } 
new point4() { ? self } 
new point5   { ? self } 
new point6   { ? self } 
new point7

class point x=10000 y=20000 z=30000

class point2

	x y z

	func init
		x=1000 y=2000 z=3000
		return self

class point3

	x=100 y=200 z=300

	func init return self

class point4

	func init
		AddAttribute(Self,[:x,:y,:z])
		x=10 y=20 z=30
		return self

class point5

	this.x = -10
	this.y = -20
	this.z = -30

class point6

	self.x = -100
	self.y = -200
	self.z = -300

class point7

	x      = -1000
	this.y = -2000
	self.z = -3000
	? self
