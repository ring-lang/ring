/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.30
*/

new point 
{			# call bracestart()
	x=10 y=20 z=30
	? self
	asasdght	# Error ---> Braceerror()
}			# call Braceend()

class point 
	x y z 

	func bracestart 
		? "Start!"

	func braceend
		? "End!"

	func braceerror
		? "Error!"
