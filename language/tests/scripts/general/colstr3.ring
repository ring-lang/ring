? "
=====================================================
We will test using Operator Overloading
(1) In standalone statements
(2) In statements that exist inside Lists
During these tests we will pass different types
to the Object as parameters (Including Lists)
=====================================================
"

myobj = new test

? "
==============================
Using Standalone Statements
==============================
"

? myobj + 1
? myobj + "string"
? myobj + [1,2,3]
? myobj = [1,2,3]

? "
==============================
Using Statements inside Lists
==============================
"

aList = [
	myobj+1,
	myobj+"mystring",
	myobj+[1,2,3],	
	myobj=[1,2,3]
]

? "
==============================
Print the List
==============================
"

? aList

? "
==============================
End of the Test Program
==============================
"


class test

	func operator cOp,cValue
		? "Operator Overloading"
		?   "operator  : " + cOp
		See "Parameter : " ? cValue
		return cValue