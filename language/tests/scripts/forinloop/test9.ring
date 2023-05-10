myobj = new MyClass(1:10)
myobj.add(11)
myobj.add(12)

for x in myobj 
	? x 
next

? myobj[1]
? myobj[10]
? myobj[12]

myobj[10] = 100
? myobj[10]

for x in myobj 
	? x 
next

class MyClass

	data

	func init val 
		data = val

	func add cStr
		data + cStr

        func operator cOperator,Para
		switch cOperator
			on "len"
				return len(data)
			on "[]"
				# Using & we support modifying the item from outside the class
				# As in myobj[10] = 100
				# Without & we get an error in myobj[10] = 100
				return &data[Para]
		off