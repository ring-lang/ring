# Using (from, to) keywords as identifiers (variables/attributes)

func main

	from = 1
	to = 10
	? from
	? to
	? copy("*",20)

	for t=from to to		# I know (to to) is not a good way to use this feature
		? t 
	next
	? copy("*",20)

	new mytest { test() }

class mytest

	From=100  To=110

	func test

		for x=from to to	# I know (to to) is not a good way to use this feature  
			? x
		next
		? copy("*",20)
			