	Screen() 
	{

		point() 
		{ 			# access the object using reference 
			x = 100 
			y = 200
			z = 300		
		}

		point() 
		{ 			# access the object using reference 
			x = 50 
			y = 150
			z = 250		
		}
	}

Func screen return new screen

Class Screen
	content = []
	func point
		content + new point
		return content[len(content)]	# return the object by reference
	func braceend
		see "I have " + len(content) + " points!"

Class point x=10 y=20 z=30
	func braceend				# will be executed after the end of object access using { }
		see self			# print the object state
