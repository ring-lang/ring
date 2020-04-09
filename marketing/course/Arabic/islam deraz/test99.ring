/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.28
*/
o1 = new person {
	name = "Mahmoud"  country = "Egypt"	
	print()
}

o2 = new employee {
	name = "Ahmed"       country = "Egypt"	
	job  = "developer"   salary  = "xxxxxxx" 
	print()
}

? o1
? o2


class person 
	name country
	func print 
		? "Name: " + name
class employee from person
	job salary
	
