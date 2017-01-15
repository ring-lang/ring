/*
	Bug ID : 201
	Description : Crash when Return temp list contains items as global/attributes variables
	Status : Fixed
*/

m = 10
o = new myclass see o.test()

class myclass
	func test
		return [m,1]
