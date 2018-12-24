? "calling 100000 functions"
t1 = clock()
for x = 1 to 100000
	test()
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

o1 = new test

? "calling 100000 methods using the dot operator"
t1 = clock()
for x = 1 to 100000
	o1.test()
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

? "calling 100000 methods using braces "
t1 = clock()
for x = 1 to 100000
	o1 { test() }
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"


func test

class test
	func test
