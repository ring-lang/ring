func main

	o1 = new myclass
	o2 = new myclass2

	talk(o1)
	talk(o2)	
	talk(o1)
	talk(o2)

func saySomething

	? "Hi"

func talk obj

	obj {
		? :before
		saySomething()
		? :after
		good()
	}

# A class that contains the saySomething() method 

class myclass

	func saySomething
		? "I'm Happy"

	func good
		? "MyClass is good"

# A class without the saySomething method

class myclass2

	func good
		? "MyClass2 is good"