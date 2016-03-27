nObjsCount = 0

oPerson = new Person
oPerson.cName = "Mahmoud"	
oPerson.cAddress = "Egypt"
oPerson.cPhone = "123456"
oPerson.show()

oPerson.nNum1 = 5
oPerson.nNum2 = 10
oPerson.sum()

oPerson.sayhello("Ahmed")
oPerson.show()

oPerson.append("one")
oPerson.append("two")
oPerson.append("three")
oPerson.print()

see "Objects Count : " + nObjsCount + nl

oPerson.test()

Class Person

	#we can access global variables
	nObjsCount = nObjsCount + 1

	cName = ""	cAddress = ""  	cPhone = ""
	nNum1 = 0	nNum2 = 0		nSum = 0

	aList = []

	func show

		see "Name : " + cName + nl
		see "Address : " + cAddress + nl
		see "Phone : " + cPhone + nl

	func sum

		nSum = nNum1 + nNum2
		see "Sum : " + nSum + nl

	func sayhello cName

		see "Hello " + cName + nl

	func append cValue

		add(aList,cValue)	

	func print

		see aList

	func test

		see "test" + nl
		test2()

	func test2

		see "test2" + nl
		
