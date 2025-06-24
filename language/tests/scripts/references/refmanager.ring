func main

	oTest  = new refManager

	myObj  = oTest.retRef()
	myObj2 = myObj		# Must be a copy by ref

	? myobj2		# 1:5
	ID1= objectid(myobj2)
	oTest.update()
	? myObj2		# 1:3
	? myobj			# 1:3
	ID2= objectid(myobj2)
	ID3= objectid(myobj)
	? ID1=ID2		# 1 (True)
	? ID2=ID3		# 1 (True)

class refManager

	aObjects = [
		1:5  ,
		1:10 
	]

	func retRef
		return ref(aObjects[1])		

	func update
		aObjects[1] = 1:3		# Replace the list with a new List