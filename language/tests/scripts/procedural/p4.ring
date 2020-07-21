
see "hello world" + NL

for x = 1 to 10
	see x
	see NL
next

aList = ["Mahmoud","Samir","Fayed"]

for x = 1 to 3
	see aList[x] + NL
next

see mywork(aList)

see NL

see work2(aList)[1]
see NL

see work2(aList)

func mywork v1
	for x = 1 to 3
		see v1[x] 
	next
	return v1[1]

func work2 v1
	temp = v1
	temp[1] = "Ahmed"
	return temp