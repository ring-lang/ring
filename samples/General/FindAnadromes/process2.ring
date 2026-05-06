# This version 
# (1) uses lower()
# (2) Avoid words that contains dash
# (3) Avoid repeating pairs

t1 = clock()
aList = sort(str2List(lower(read("words.txt"))))
t2 = clock()

? copy("=",40)
nMax = len(aList)
for t=1 to nMax
	cWord = aList[t]
	if len(cWord) > 6 and !substr(cWord,"-")
		aList[t] = "."
		if binarysearch(aList,reverse(cWord)) 
			? cWord + " - " + reverse(cWord) 
		ok
	ok 
next
t3 = clock()
? copy("=",40)

? "Loading file & sorting data: " + (t2-t1) + " ms"
? "Search and finding words: "    + (t3-t2) + " ms"
? "Total Time: "                  + (t3-t1) + " ms"
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
rotanev - venator
roygbiv - vibgyor
sallets - stellas
sennits - stinnes
========================================
Loading file & sorting data: 1461 ms
Search and finding words: 345 ms
Total Time: 1806 ms
========================================
*/
