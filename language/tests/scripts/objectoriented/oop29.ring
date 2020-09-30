o1 = new Person {

	name = "mahmoud" address = "Egypt"
	phone = "123456" 
	
	try 
		o1 {
			see "job : " + getjob() + nl
		}
	catch
		see "can't call private mehtod" + nl
	done
	
}

o1.print()
O1.TEST()

try
	see o1.salary + nl
catch
	see "can't use private attribute" + nl
done

see o1.getjob() + nl
see o1.getsalary() + nl

func mytest
	o1 {
	}

Class Person

	name address phone

	func print 
		see "name : " + name + nl +
		    "address : " + address + nl + 
		    "phone : " + phone + nl  + 
		    "job : " + self.getjob() + nl

	func test
		self {
			name = "Ali" address = "KSU"
			phone = "123456" job = "programmer"
			salary = 1500
			print()
			see "job : " + getjob() + nl
		}
		mytest()

	private
	
	job = "Software Engineer"
	salary = 14000

	func getjob	return job
	func getsalary	return salary