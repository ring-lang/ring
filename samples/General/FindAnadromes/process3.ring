# This version uses Ring List as HashTable

t1 = clock()
aList = str2List(lower(read("words.txt")))
t2 = clock()

aHash = []
nMax = len(aList)
for t=1 to nMax
	if len(aList[t]) > 6
		aHash[aList[t]] = True
	ok
next

t3 = clock()
aWords = []
for t=1 to nMax
	if len(aList[t]) > 6
		cKey = reverse(aList[t])
		if (aHash[cKey] = True) and (cKey != aList[t]) and (! substr(cKey,"-")) and 
		   (! find(aWords,cKey)) and (! find(aWords,aList[t]))
			aWords + aList[t]
		ok
	ok
next
? copy("=",40)
for cWord in aWords
	? cWord + " - " + reverse(cWord)
next
t4 = clock()

? copy("=",40)
? "Words Count (result): " + len(aWords)
? "Loading file: " + (t2-t1) + " ms"
? "Adding data to the HashTable: " + (t3-t2) + " ms"
? "Search and finding words: "    + (t4-t3) + " ms"
? "Total Time: "                  + (t4-t1) + " ms"
? copy("=",40)

/*
Output on my machine:

========================================
amaroid - diorama
anacara - aracana
annabal - labanna
artamus - sumatra
colbert - trebloc
degener - reneged
deifier - reified
delbert - trebled
delevan - naveled
deliver - reviled
dessert - tressed
desserts - stressed
deviler - relived
dioramas - samaroid
eimmart - trammie
emmeram - maremme
gateman - nametag
latimer - remital
lattimer - remittal
lessees - seessel
leveler - relevel
nicolaus - sualocin
redrawer - rewarder
reknits - stinker
relever - reveler
reliver - reviler
revotes - setover
roygbiv - vibgyor
rotanev - venator
sallets - stellas
sennits - stinnes
========================================
Words Count (result): 31
Loading file: 57 ms
Adding data to the HashTable: 366 ms
Search and finding words: 564 ms
Total Time: 987 ms
========================================
*/
 