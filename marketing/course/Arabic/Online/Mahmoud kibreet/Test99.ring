/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.30
*/

o1 = new person {
	name = "Mahmoud" country = "Lebanon"
	print()
}

o2 = new employee {
	name = "Kibreet" country = "Beirut" job = "developer"
	salary = "xxxxxxxxx"
	print()
}

? o1
? o2

class person 
	name country
	func print
		? "Name : " + name

class employee from person
	job salary
