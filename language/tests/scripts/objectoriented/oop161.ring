# Using (from, to, step) keywords as identifiers (variables/attributes)
# I know that using (to to) and (step step) is not a good way to use this feature  

func main

	from = 1
	to   = 10
	step = 2
	? from
	? to
	? step
	? copy("*",20)

	for t=from to to step step
		? t 
	next
	? copy("*",20)

	new mytest { test() }

class mytest

	From=100  To=200  Step=10 

	func test

		for x=from to to step step
			? x
		next
		? copy("*",20)
			