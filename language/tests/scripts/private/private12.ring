new happy

class happy

	o1 = new child
	o1.test1()

	try
		o1.good()
	catch 
		? :pass1 
	done
	
	try
		o1 { good() }
	catch
		? :pass2
	done

class parent
	func test1
		? :test1

	private
		func good
			? :good

class child from parent
	test1()
	good()
	wow()
	? name	# We expect NULL
	? "great"
	self.test1()
	self { test1() }
	this.test1()
	this { test1() }

	self.wow()
	self { wow() }
	this.wow()
	this { wow() } 

	self.good()
	self { good() }
	this.good()
	this { good() } 
	
	private
		name = :child
		? name
		func wow
			? :Wow