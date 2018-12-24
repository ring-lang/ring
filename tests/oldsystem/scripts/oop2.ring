func main

	nice()
	r = 1
	see "r value : " + r + nl

	oTest = new test

	see oTest
	#see "object cName value " + oTest.cName + nl

	see oTest.cName 
	see nl 
	oTest.cName = "Ahmed"
	see oTest.cName 
	see nl 
	
	see "r value : " + r + nl
#	see "cName value : " + cName + nl

	nice()
	see oTest

	#oTest.nice()

func nice

	see "good" + nl

class test

	SEE "I am here" + nl

	cName = "Mahmoud"
	cAddress = "Egypt"
	cPhone = "123456789"
	r = 0

	see "cName value : " + cName + nl

	func nice
		see "ok" + nl