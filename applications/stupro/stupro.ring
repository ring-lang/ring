# Application : Students Progress (StuPro)
# Usage       : Return statistics about the number of applications made by PWCT Students!
# Author      : Mahmoud Fayed <msfclipper@yahoo.com>

Func Main
	WriteIndex()
	aList = GetStudents()
	see aList
	list2File(aList,"students.txt")
	aList = GetApps(aList)
	see aList
	list2File(aList,"applications.txt")
	oneApplication(aList)
	aList = GetLevel(aList)
	see aList
	list2File(aList,"level.txt")
	LevelNumber(aList)

Func LevelNumber aList
	n1 = 0 n2=0 n3=0
	for x in aList
		switch x
		on 1  n1++
		on 2  n2++
		on 3  n3++
		off
	next
	see "level 1 : " + n1 + nl +
	"level 2 : " + n2 + nl +
	"level 3 : " + n3 + nl 

Func OneApplication aList
	nCount = 0
	for x in aList if x = 1 nCount++ ok next
	see "Students created only 1 applications : " + nCount + nl

Func WriteIndex
	aList = 1:298
	for x in aList x = string(x) next
	list2file(aList,"index.txt")

Func List2File aList,cFileName
	cStr = list2str(aList)
	cStr = substr(cStr,nl,windowsnl())
	write(cFileName,cStr)

Func GetApps aList
	aApps = []
	for x in aList
		if not trim(x) = ""
			nApps = GetTotals("https://sourceforge.net/projects/doublesvsoop/files/PWCT%20For%20MS-Windows/PWCT%20Students/"+x+"/")
			aApps+nApps
		ok
	next
	return aApps

Func GetStudents
	aFolders = []
	cBase = "https://sourceforge.net/projects/doublesvsoop/files/PWCT%20For%20MS-Windows/PWCT%20Students/"
	cBase = download(cBase)
	nPos = 1
	while nPos > 0
		nPos  = substr(cBase,'<tr title="')
		cBase = substr(cBase,nPos+11)
		nPos  = substr(cBase,'"')
		cItem = left(cBase,nPos-1)
		aFolders + cItem
		nPos  = substr(cBase,'<tr title="')
	end
	del(aFolders,len(aFolders))
	return aFolders

Func GetTotals cLink
	cLink = trim(cLink)
	cLink = substr(cLink," ","%20")
	cStr =  download(cLink)
	cStr = substr(cStr,substr(cStr,"Totals:"), 100)
	cStr = substr(cStr,"</span>","")
	cStr = left(cStr,substr(cStr,"Item")-1)
	cStr = substr(cStr,8)
	see cStr
	return cStr

Func GetLevel aList
	aLevel = []
	for x in aList
		x = 0+x
		if x <= 32 
			aLevel + "1"
		but x > 32 and x<=50
			aLevel + "2"
		else
			aLevel + "3"
		ok
	next
	return aLevel
