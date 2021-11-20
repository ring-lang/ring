o1 = new point { x = 10 y = 10 print("Point 1: ") }
o2 = new point { x = 20 y = 40 print("Point 2: ") }

r = o1 + "Hello"
r = o1 + 2015
r = o1 + o2
r = o1 - "Hello2"
r = o1 - 2014
r = o1 - o2
r = o1 * "Hello3"
r = o1 * 2016
r = o1 * o2
r = o1 / "Hello4"
r = o1 / 2000
r = o1 / o2
r = o1 % "Hello5"
r = o1 % 2001
r = o1 % o2
vlist = [1,2,3]
r = o1 + vlist
r = o1 - vlist
r = o1 * vlist
r = o1 / vlist
r = -o1
if o1 = o2 ok 
if o1 = 1 ok 
if o1 = "one" ok 
if o1 <= o2 ok
if o1 <= 1 ok 
if o1 <= "one" ok 
if o1 < o2 ok
if o1 < 1 ok 
if o1 < "one" ok 
if o1 > o2 ok
if o1 > 1 ok 
if o1 > "one" ok 
if o1 >= o2 ok
if o1 >= 1 ok 
if o1 >= "one" ok 
if o1 != o2 ok 
if o1 != 1 ok 
if o1 != "one" ok 
if o1 & o2 ok 
if o1 & 1 ok 
if o1 & "one" ok 
if o1 | o2 ok 
if o1 | 1 ok 
if o1 | "one" ok 
r = not o1
r = o1 % vlist
see r

class point x y

	func operator cOperator,cPara
		see "operator overloading works fine" + nl
		see "parameters : " 
		see cPara see nl
		see "operator : " + cOperator + nl
		return self


	func operator2 cOperator,aPara
		result = new point	
		switch cOperator
		on "+"
			result.x = x + aPara.x
			result.y = y + aPara.y
		on "-"
			result.x = x - aPara.x
			result.y = y - aPara.y
		off
		return result

	func print cPoint
		see cPoint + "X : " + x + " Y : " + y + nl
