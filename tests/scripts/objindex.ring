func main

p1 = new point
see p1[5] + nl
see p1["string index"] + nl
see len(p1) + nl

o1 = new mylist
o1.add("one")
o1.add("two")
o1 {
	add("three") add("four") add("five")
}

see "size : " + len(o1) + nl

see "Type : " + type(len(o1)) + nl

r = o1[3]
see "r value = " + r + nl

for x = 1 to 5
	see "x value = " + X + nl
	see o1[x] + nl
	#o1[x] = ""
next

see "test loop... " + nl
for x = 1 to len(o1)
	see o1[x] + nl
next

see "Using for in " + nl

o1 = new mylist
o1.add(["one"])
o1.add(["two"])
o1.add(["three"])

for x in o1
	see x 
next

for x in o1
	see x
next

class point x y z
	func operator cOperator,cValue
		see "Operator Overloading" + nl
		see "Operator : " + cOperator + nl
		see "Value    : " + cValue + nl

Class MyList
	aItems = []
	func add cValue
		aItems + cValue
	func operator cOperator,cValue
		if cOperator = "[]"
			return aItems[cValue]
		but cOperator = "len"
			return len(aItems)
		ok