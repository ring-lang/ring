load "stdlib.ring"

sList = newlist(8, 2)
aList = ["Here", "are", "some", "sample", "strings", "to", "be", "sorted"]
ind = len(aList)

for n = 1 to ind
    sList[n] [1] = aList[n]
    sList[n] [2] = len(aList[n])
next

nList = sortFirstSecond(sList, 2)
oList = newlist(8, 2)
count = 0

for n = len(nList) to 1 step -1
    count = count + 1
    oList[count] [1] = nList[n] [1]
    oList[count] [2] = nList[n] [2]
next

for n = 1 to len(oList) - 1
    temp1 = oList[n] [1]
    temp2 = oList[n+1] [1]
    if (oList[n] [2] = oList[n+1] [2]) and (strcmp(temp1, temp2) > 0)
       temp = oList[n] [1]
       oList[n] [1] = oList[n+1] [1]
       oList[n+1] [1] = temp
     ok
next

for n = 1 to len(oList)
    see oList[n] [1] + nl
next
