# Ring Classes 

func main 

	new test 
	new test2 
	? new test3
	myobj = new test4
	? myobj 
	myobj.sayhello()
	
	myobj {
		name = "Mahmoud"
		SayHello()
	}
	
	myobj.name = "Ahmed"
	myobj.sayhello()
	
	? myobj
	
	myobj2 = new test4 {
		name = "Ibrahim"
		sayhello()
	}
	
	new test5 
	myobj = new test5() 	# here using () we can call the init() method 
	
	myobj2 = new test6() {
		name = "Ali"
		SayHello()
	}	
	
	myobj3 = new test7("Ring Language")
	myobj3.sayhello()
	
	myobj = new test8("Mahmoud","Programmer")
	myobj.sayHello()
	
	# In Ring we are using comma , only to separate between parameters 
	# When we call functions/methods 
	
	# Inside braces we don't write comma 
	# why ?
	# because we are writing normal Ring code 
	
	/*
		object {
			// statements - normal Ring code 
		}
	
	*/

class test 
	# An Empty

class test2
	# The Class Region 
	# We can execute any ring code 
	? "Hello, World!"

class test3 
	# In this region (Class Region)
	# New variables become the Object Attributes 
	Name = "Ring" 

class test4
	Name = "Ring" 
	func SayHello 
		? "Hello " + Name

class test5

	Name = "Ring"

	func init 
		? "Hello from init"

	func SayHello 
		? "Hello " + Name

class test6

	Name = "Ring"

	func init 
		? "Hello from init"
		return self		# so we can use {} after init() method 

	func SayHello 
		? "Hello " + Name
	
class test7

	Name = "Ring"

	func init  cName 
		Name = cName 
		return self		# so we can use {} after init() method

	func SayHello 
		? "Hello " + Name
	
class test8

	Name = "Ring"
	Job  = "" 

	func init  cName,cJob
		Name 	= cName 
		Job 	= cJob
		return self		# so we can use {} after init() method 

	func SayHello 
		? "Hello " + Name
		? "You are a " + Job
