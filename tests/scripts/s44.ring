
aList = ["mohammad","mahmoud","ahmad","ibrahim"]
aList2 = [1,2,3,4,5,6,7,8,9,0]
aList3 = ["Mahmoud",1,10,"Ahmad"]
aList4 = [1,3,4,[5,6,7,[8,9,10],11],12,["ahmad",4,5]]
for x = 1 to 4
	see aList[x] + NL
next
#aList[1] = "nice"
for x = 1 to 10
	see aList2[x]  
	see NL
next
for x = 1 to 4
	see aList3[x] 
	see NL
next
see aList4[4][1]
see NL
see aList4[4][4][1]
see NL

for x = 1 to 3
	see aList4[5]
	see NL
next
 
 see aList4[6][1]
 see aList4[6][2]
 see aList4[6][3]

 for x = 1 to 3
 	see aList4[6][x]
 	see NL
 next

see aList4[4][4][3]
see NL

x = 4
y = 4
z = 3
see aList4[x][y][z]
see NL

cName = "Mahmoud"
aList5 = [["mohammad","samir","fayed"],[cName,"samir","fayed"],["ahmad","samir","fayed"],["ibrahim","samir","fayed"]]

for x = 1 to 4
	for y = 1 to 3
		see aList5[x][y] + " "
	next
	see NL
next

