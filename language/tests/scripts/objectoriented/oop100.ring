# When we create an object it will contains the Super attribute
# We can't modify this attribute
#
# Also, if we have a global variable called Super then we can't access it
# directly from the class 

super = :GOOD
? super
? new myclass 

func printSuper
	? super

class myclass
	try
		super = :good
	catch 
		? "We can't update the Super attribute"
	done
	printSuper()
