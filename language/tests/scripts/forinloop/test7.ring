aList = [
	"Test",
	["one","two","three"],
	new generator,
	2023
]

for x in aList[1]
	? x
next

for x in aList[2]
	? x
next

for x in aList[3]
	? x
next

try
	for x in aList[4]
		? x
	next
catch
	? "We can't use For-In loop with numbers"
done

class generator
	func operator cOp,vValue
		if cOp = "len"
			return 10
		but cOp = "[]"
			return vValue
		ok