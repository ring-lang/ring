$global_variable = 5

new test { hello() }	

class test

	@instance_variable = 10

	func hello

		local_variable = 15

		see "Global   : " + $global_variable + nl + 
		    "Instance : " + @instance_variable + nl +
		    "Local    : " + local_variable + nl