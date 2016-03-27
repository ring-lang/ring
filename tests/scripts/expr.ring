FUNC MAIN
see "logic" + nl
see ("1" and "0") + nl
see ("1" and "1") + nl
see ("1" and 0) + nl
see ("1" and 1) + nl
see (1 and "0") + nl
see (1 and "1") + nl
see ("1" or "0") + nl
see ("1" or "1") + nl
see ("1" or 0) + nl
see ("1" or 1) + nl
see (1 or "0") + nl
see (1 or "1") + nl
see "not" + nl
see (not "0") + nl
see (not "1") + nl
see (not 0) + nl
see (not 1) + nl
see "more" + nl
see ("5" < 3) + nl
see ("5" <= 3) + nl
see ("5" > 3) + nl
see ("5" >= 3) + nl
see ("5" = 3) + nl
see ("5" != 3) + nl
see (5 < "3") + nl
see (5 <= "3") + nl
see (5 > "3") + nl
see (5 >= "3") + nl
see (5 = "3") + nl
see (5 != "3") + nl
see (5 < 3) + nl
see (5 <= 3) + nl
see (5 > 3) + nl
see (5 >= 3) + nl
see (5 = 3) + nl
see (5 != 3) + nl
see "math" + nl
see "3" - "1" + nl
see "3" - 2 + nl
see 10 - 2 + nl
see 10 - "3" + nl
see "mul" + nl
see "3" * "1" + nl
see "3" * 2 + nl
see 10 * 2 + nl
see 10 * "3" + nl
see "div" + nl
see "3" / "1" + nl
see "3" / 2 + nl
see 10 / 2 + nl
see 10 / "3" + nl
see "negative" + nl
see (-"10") + nl
see (-11) + nl
see "mod" + nl
see "3" % "1" + nl
see "3" % 2 + nl
see 10 % 2 + nl
see 10 % "3" + nl
see "more " + nl
t1 = [1,2,3]
t2 = [4,5,6]
see t1 + t2

name = "mahmoud" see name + nl
test(name[1]+ "ah" + nl)
see ("6" = 5) + nl
see (6 = "5") + nl
see ("5" < 6) + nl

o1 = new point { x = 10 y = 10 print() }
o2 = new point { x = 20 y = 40 print() }

see "i am here" + nl
r = o1 + o2
r.print()

func test x
see x 

class point x y

	func operator cOperator,aPara
		switch cOperator
	 	on "+"
			x = x + aPara.x
			y = y + aPara.y
		off		 
		return self

	func print
		see "X : " + x + " Y : " + y + nl