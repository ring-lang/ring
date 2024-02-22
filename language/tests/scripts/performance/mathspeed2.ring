num1 = 123456.11
num2 = 123456.23
aList = []
t1 = clock()
for x = 1 to 1000000
	num3 = num1+x
	aList + num3
next
? "Time (Sum Operation - 1000000 times) : " + (clock()-t1)/clockspersecond() + " seconds"

t1= clock()
for x = 1 to 1000000
	num3 = num2*x
	aList + num3
next
? "Time (Mul Operation - 1000000 times) : " + (clock()-t1)/clockspersecond() + " seconds"
? "Len(aList) = " + len(aList)
