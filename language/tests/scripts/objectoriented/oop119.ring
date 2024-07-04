o = new Class2

o + 10
? "******"

10 + o
? "******"

"Message" + o
? "******"

"Message" * o
? "******"

mylist = 1:5

? o and mylist
? "******"

# mylist will be converted to 1 (True)
? mylist and o		
? "******"

? "Some logic.."
myClass1 = new Class1
? mylist and myClass1	# True
? mylist or myClass1	# True
? myClass1 or mylist	# True
? "******"

? "Conversion because of short-circuit"
# "Message" will be converted to 1 (True)
? "Message" and o	# Call the operator() method
? "Message" or  o	# No operator-overloading here	
# 12 will be converted to 1 (True)
# Number (12) will be converted to 1 (True)
? 12 and o		# Call the operator() method
? 12 or o		# No operator-overloading here	
? "******"
? "Logic and pure values"
? 12 or "Class2"
? "Class2" or 12
? [1,2,3] and 1
? [1,2,3] or "Class2"
? (11 and 12)
? (11 or 12)
? "******"
? "Extra..."
# The empty string "" will be converted to 0 (False)

? 0 or o
? "" or o	
? "Using Not..."
? !  14
? ! 0
? ! ""
? ! "t"

? "List then object and operator-overloading"
? [1,2,3] - o

Try
	? "Let's have an error message"
	? 15 * [2,3]
Catch
	? cCatchError
Done

? "Thanks!"

class Class1
	# Doesn't have the operator() method

class Class2

	func operator cop,vvalue
		? "oo"
		? cop
		? vvalue