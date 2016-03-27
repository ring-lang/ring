o1 = new string("Hello")
o1.print()
see o1.size + nl

mylist = new list( [1,2,3,4,5,6,7,8,9,10] )
mylist.add(11)
mylist.add("nice")
mylist.print()
see mylist.size

Class String
	
	value = ""
	size = 0
	
	func init cStr
		value = cStr
		size = len(value)

	func print
		see value + nl

class list

	value = []
	size = 0

	func init aList
		value = aList
		size  = len(value)

	func print
		see value

	func add  cItem
		value + cItem
		size++
