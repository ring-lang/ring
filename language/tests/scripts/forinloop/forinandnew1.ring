# Author: Ilir Liburn

for y in new Test
	exit
next

? " WHOOPS " + ring_see(y) 
? :done

class Test

	func operator cOp,cVal

		switch cop
			on "len"
				return 1
			on "[]"
				return char(116)
		off
