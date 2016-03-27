o1 = new person {
	name = "Test"
	age = 20
	print()
	printsalary()
}

try
	see o1.salary
catch
	see cCatchError + nl
done

try
	o1.increasesalary(1000)
catch
	
	see cCatchError + nl
done



Class Person

	name age 

	func print
		see "Name   : " + name + nl + 
		    "Age    : " + age + nl 

	func printsalary
	  	see "Salary : " + salary + nl 

	private

	salary = 15000

	func increasesalary x
		salary += x