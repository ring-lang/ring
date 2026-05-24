C_COUNT = 1_000_000
? "calling "+C_COUNT+" functions"
t1 = clock()
for x = 1 to C_COUNT
	test()
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

o1 = new test

? "calling "+C_COUNT+" methods using the dot operator"
t1 = clock()
for x = 1 to C_COUNT
	o1.test()
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

? "calling "+C_COUNT+" methods using braces "
t1 = clock()
for x = 1 to C_COUNT
	o1 { test() }
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"


func test

class test
	func test
