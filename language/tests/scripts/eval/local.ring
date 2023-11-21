x = 100	# Global Variable

func main
	? x	# Print Global variable
	test()	
	? x	# Print Global variable

func test
	local(:x)	# Define local variable called x
	? x		# Print local variable - x will be NULL 
	x = 1000	# set the local variable 
	? x		# Print the local variable


func local cVar

	ringvm_evalinscope(ringvm_scopescount()-1,"for "+cvar + " = 1 to 1 next " + cvar + " = 'NULL'" )