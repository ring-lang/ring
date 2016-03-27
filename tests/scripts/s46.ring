
aList = [[0,0],[0,0],[0,0],[0,0],[0,0]]

for x =  1 to 5
	aList[x][1] = x
	aList[x][2] = x * x
next

for x =  1 to 5
	see aList[x][1] 
	see " "
	see aList[x][2]
	see NL
next

