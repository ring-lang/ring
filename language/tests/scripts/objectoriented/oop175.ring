x=10 y=20 z=30					# Global Variables

cFunc = func { ? :good ? x ? y ? z  }

func main 

new point {

	? self
	test()
	? copy("=",50)
	call cFunc() 				# Call as Function
	? copy("=",50)
	happy()
	? copy("=",50)
	call { cFunc() }			# Call as Method
	? copy("=",50)
	nice()
	? x ? y ? z
}	

class point

	# We use (self) because we have x,y and z as global variables 

	self.x=100 self.y=200 self.z=300	# Attributes

	func test 
		? :test

	func happy
		? :happy
		? x
		? y
		? z

	func nice
		? copy("=",50)
		? :nice
		call cFunc()			# Call as Function
		call { cFunc() }		# Call as Method
		? copy("=",50)