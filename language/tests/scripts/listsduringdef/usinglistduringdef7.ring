aList = NULL			# Global Variable
test()
aList = :wow			# Protection is removed 
? alist				# Print wow

func test
	try
		test2()		# Pass the error
	catch 
	done

func test2
	aList = [				# Protected List
		100,200,300,
		new point { m=[] error }	# Runtime Error
	]

class point x y z