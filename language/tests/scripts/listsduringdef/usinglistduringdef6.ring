aList = NULL		# Use global variable
test()
aList = :wow		# Protection is removed by State Manager
? aList			# Print wow

func test
	aList = [
		100,200,300,
		new point { return } # Return while list is protected
	]

class point x y z