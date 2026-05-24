nMethodsCount = 1_000_000
? "calling "+nMethodsCount+" functions"
t1 = clock()
for x = 1 to nMethodsCount
	test()
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

o1 = new test

? "calling "+nMethodsCount+" methods using the dot operator"
t1 = clock()
for x = 1 to nMethodsCount
	o1.test()
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

? "calling "+nMethodsCount+" methods using braces "
t1 = clock()
for x = 1 to nMethodsCount
	o1 { test() }
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"


func test

class test
	func test
