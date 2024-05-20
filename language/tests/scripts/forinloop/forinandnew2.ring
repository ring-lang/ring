# Author: Ilir Liburn

for y in new Test
	exit
next

? "WHOOPS" + ring_see(y)
? :done

class Test

	test2 = new Test2

	func operator cOp,cVal
		switch cop
			on "len"
				return len(test2)
			on "[]"
				return test2[cVal]
		off

class Test2

	func operator cOp,cVal

		switch cop
			on "len"
				return 1
			on "[]"
				return char(33)
		off