/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.04.14
*/

/*

	Variables Scope 
		Three scopes
			[1] Global scope
			[2] Object scope
			[3] Local scope	

*/
# lexical scoping (scope of variable is based on location)
 
x = 10 		# Global variable	

func main 
	y = 10	# local variable	
	? x
	test()
	? y
	new person {		# Inside the object scope
		name ="Hamza"
		address ="Egypt"
		phone ="xxxxx"
		? self
	

}

func test
	? x

class person	
	name address phone


