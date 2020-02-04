
/*
e1 = new employee
e1.empNO = 111
e1.empName = "Omar"
e1.salary = 13000
e1.printData()
*/

e1 = new employee{ empNO=1 empName="Amr" salary=14000 }
e2 = new employee{ empNO=2 empName="Ali" salary=15000 }
e3 = new employee{ empNO=3 empName="Omar" salary=12500 }

e1.printData()
e2.printData()
e3.printData()

class employee{

	empNO
	empName
	salary

	func printData{
		see "NO:" + empNO +  " ; Name:" + empName + " ; Salary:" + salary + nl
	}	

}

