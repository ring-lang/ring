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

# Conflict between the class|object attribute and local variable 

new test{ 
	mytest() 
	sayhello("Hamza")
	? @name
}



class test 
	@name = "ring"

	func mytest
		? @name
	

	func sayhello p1
		name = "Mr. " + p1
		? "Hello " + name

