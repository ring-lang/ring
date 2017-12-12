load "stdlib.ring"

cDoc = read("qtclassesdoc.txt")

aList = str2list(cDoc)

nMax = len(aList)
nStart = False
cClassData = ""
cClassName = ""

aData = []
for x = 8 to nMax
	cLine = trim(aList[x])
	if startswith(cLine,".. index::")
		if nStart=False
			nStart = True
			cClassData = cLine + nl
		else 
			aData + [cClassName,cClassData]
			nStart = True
			cClassData = cLine + nl
		ok			
		loop
	ok
	if nStart 
		cClassData += cLine + nl	
	ok
	if startswith(cLine,"===")
		cClassName = aList[x-1]
	ok
next

if nStart
	aData + [cClassName,cClassData]
ok

sort(aData,1)

remove("qtclassesdoc2.txt")
fp = fopen("qtclassesdoc2.txt","a+")
	for x = 1 to 8
		fwrite(fp,aList[x]+nl) 
	next
	for aClass in aData 
		fwrite(fp,aClass[2])
	next
fclose(fp)

