fCheck = func {
	? copy("=",50)
	? "One day, I will no longer remain just a function."
	? "One day, I will live as a method inside an object."
	? "That object will have a place in a 3D world."
	? "And it will have the x, y, and z attributes."
	Try
		? "X= " + x 				# Use Attributes
		? "Y= " + y
		? "Z= " + z
		? "The dream has come true."
		print()					# Call Method
	Catch
		? "Not yet!"
	Done
}

call fCheck()						# Call fCheck as Function

new point { x=10 y=20 z=30 call {fCheck()} }		# Call fCheck as Method

class Point

	x y z

	func print
	
		? self