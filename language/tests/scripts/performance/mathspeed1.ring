num1 = 123456
num2 = 123456
t1 = clock()
for x = 1 to 1000000
	num3 = num1+num2
next
? "Time (Sum Operation - 1000000 times) : " + (clock()-t1)/clockspersecond() + " seconds"

t1= clock()
for x = 1 to 1000000
	num3 = num1*num2
next
? "Time (Mul Operation - 1000000 times) : " + (clock()-t1)/clockspersecond() + " seconds"