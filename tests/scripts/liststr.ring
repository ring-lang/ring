cStr = read("b:\mahmoud\apps\ring\test.txt")

if iswindows()
	cStr = substr(cStr,windowsnl(),nl)
ok

aList = str2list(cStr)
cStr2 = list2str(aList)

if iswindows()
	cStr2 = substr(cStr,nl,windowsnl())
ok

write("b:\mahmoud\apps\ring\test2.txt",cStr2)

cStr3 = ""
for t in aList
	cStr3 += t + nl
next

if iswindows()
	cStr3 = substr(cStr3,nl,windowsnl())
ok

write("b:\mahmoud\apps\ring\test3.txt",cStr3)

cStr4 = ""
for t in aList
	cStr4 += t 
next
write("b:\mahmoud\apps\ring\test4.txt",cStr4)