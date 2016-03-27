newmap = "a":"z"

aBaseMap = [
["a1","a2","b1","b2","c1","c2"] ,
["a1","a2","b1","b2","c1","c2","c3"],
["a1","a2","b1","b2","b3","b4","b5","b6","b7","b8"],
["a1","a2","b1","b2","c1","c2"],
["a1","a2","a3","a4","a5","a6","a7","a8","a9","a10"],
["a1","a2","b1","b2"],
["a1","a2","b1","b2"],
["a1","a2","a3","a4"],
["a1","a2","a3","a4","a5","a6"],
["a1","a2","b1","b2","b3","b4"],
["a1","a2","a3"],
["a1","a2","b1","b2","b3","b4","b5","b6"],
["a1","a2","b1","b2","b3"],
["a1","a2","a3","a4","a5","a6","a7","a8"],
["a1","a2","b1","b2","b3"]
]

aScratch = [
["a1","b1","c2"],
["c1","c2"],
["a1","b1","b3"],
["a1","b1","c1"],
["a1","a6","a8","a10"],
["a1","b1"],
["a1","a2"],
["a1"],
["a1"],
["a1","b2"],
["a1"],
["a1","b1"],
["a1","b1"],
["a1","a2","a3","a4","a5","a8"],
["a1","b2"]
]

aAlice = [
["a1","b1","c2"],
["b1","c2"],
["a1","b3","b4"],
["a1","b1","c1"],
["a1","a2","a6","a8","a10"],
["a1","b1","b2"],
["a1","a2"],
["a1"],
["a1","a3"],
["a1"],
["a1"],
["a1","b2"],
["b2"],
["a1","a2","a3","a4","a5","a8"],
["a1","b2"]
]

aPrograph = [
["a2","b1","c1"],
["a1","b1"],
["a1","b4","b5"],
["a1","b1","b2","c2"],
["a1","a2","a6","a7"],
["a2"],
["a1","b1"],
["a1","a2"],
["a1","a4"],
["a2","b3"],
["a1"],
["a2","b2"],
["b2"],
["a4"],
["b3"]
]


aLabView = [
["a2","b1","c1"],
["c1","c2","c3"],
["a2","b5"],
["a1","b2","c2"],
["a1","a2","a3","a6","a7"],
["a2","b1"],
["a1","b1"],
["a1","a2"],
["a1","a5"],
["a1"],
["a1","a2"],
["a2","b3","b4"],
["a1","b3"],
["a1","a8"],
["a1","b1"]
]

aForms = [
["a2","b1","c1"],
["c1","c2"],
["a2","b2","b7"],
["a1","b1","c2"],
["a1","a3","a4"],
["a2"],
["a1"],
["a1"],
["a1"],
["a2","b4"],
["a3"],
["a2"],
["b2"],
["a3","a5"],
["a2"]
]

aVIPR = [
["a2","b1","b2","c1"],
["a1","c2"],
["a1","b1","b4","b6"],
["a2"],
["a8"],
["a2"],
["b1","b2"],
["a1","a3","a4"],
["a1","a6"],
["a2","b3"],
["a2"],
["a2","b3","b5"],
["b2"],
["a6"],
["a2"]
]

aLimnor = [
["a1","b1","c1"],
["a1","c2"],
["a1","b3","b4","b8"],
["a1","b1","c2"],
["a1","a2","a6","a9"],
["a2"],
["a1","b1"],
["a1","a4"],
["a1","a3"],
["b1"],
["a1","a2"],
["a2","b2"],
["b2"],
["a1","a2","a3"],
["a1","b1"]
]

aTersus = [
["a2","b1","c1"],
["b1","c2"],
["a2","b5"],
["a1","b1","b2","c1"],
["a1","a6"],
["a2"],
["a1","b1"],
["a1","a4"],
["a1","a6"],
["a1"],
["a1","a2"],
["a2","b6"],
["b2"],
["a2","a3","a8"],
["a1","b1"]
]

aEnvision = [
["a2","b1","b2","c1"],
["a1","a2"],
["a1","b1","b4"],
["a1","b1","c1"],
["a3","a5"],
["a1"],
["a1","b2"],
["a1","a4"],
["a1","a6"],
["a1"],
["a1","a2"],
["a2","b2","b6"],
["b2"],
["a5","a7"],
["b2"]
]

aLava = [
["a2","b1","c1"],
["b1","c2"],
["a2","b4"],
["a1","b1","c1"],
["a3","a5","a9"],
["a1"],
["a1"],
["a1","a4"],
["a1","a6"],
["a1"],
["a1","a2","a3"],
["a1","b2"],
["b2"],
["a3","a5","a8"],
["a1","b3"]
]

#print(aScratch,aBaseMap)
#print(aAlice,aBaseMap)
#printcol(aPrograph,aBaseMap)
#printcol(aLabView,aBaseMap)
#printcol(aForms,aBaseMap)
#printcol(aVIPR,aBaseMap)
#printcol(aLimnor,aBaseMap)
#printcol(aTersus,aBaseMap)
#printcol(aEnvision,aBaseMap)
printcol(aLava,aBaseMap)

Func Print aSel,aMap
	for nCr = 1 to len(aMap)
		a = aMap[nCr]
		See copy("*",50) + nl
		See "Cr" + nCr + nl
		See copy("*",50) + nl
		for x=1 to len(a)
			See newmap[x] 
			cItem = a[X]
			if find(aSel[nCr],cItem)
				see " : True"
			ok
			see nl
			
			
		next	
	next

Func PrintCol aSel,aMap
	for nCr = 1 to len(aMap)
		a = aMap[nCr]
		#See copy("*",50) + nl
		#See "Cr" + nCr + nl
		#See copy("*",50) + nl
		for x=1 to len(a)
			#See newmap[x] 
			cItem = a[X]
			if find(aSel[nCr],cItem)
				see "T"
			ok
			see nl
			
			
		next	
	next
