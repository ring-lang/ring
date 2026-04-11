# This version uses lower()
# Also, avoid words that contains dash

t1 = clock()
aList = sort(str2List(lower(read("words.txt"))))
t2 = clock()

? copy("=",40)
nMax = len(aList)
for t=1 to nMax
	if len(aList[t]) > 6 and !substr(aList[t],"-") and binarysearch(aList,reverse(aList[t])) 
		? aList[t] + " - " + reverse(aList[t]) 
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
adinida - adinida
amaroid - diorama
anacara - aracana
annabal - labanna
aracana - anacara
artamus - sumatra
colbert - trebloc
deedeed - deedeed
degener - reneged
deified - deified
deifier - reified
delbert - trebled
delevan - naveled
deliver - reviled
dessert - tressed
desserts - stressed
deviler - relived
diorama - amaroid
dioramas - samaroid
eimmart - trammie
emmeram - maremme
gateman - nametag
hagigah - hagigah
halalah - halalah
kinnikinnik - kinnikinnik
labanna - annabal
latimer - remital
lattimer - remittal
lessees - seessel
leveler - relevel
malayalam - malayalam
maremme - emmeram
murdrum - murdrum
nametag - gateman
nauruan - nauruan
naveled - delevan
nicolaus - sualocin
ottetto - ottetto
peeweep - peeweep
redrawer - rewarder
reified - deifier
reifier - reifier
reknits - stinker
relevel - leveler
relever - reveler
relived - deviler
reliver - reviler
remital - latimer
remittal - lattimer
reneged - degener
repaper - repaper
reveler - relever
reviled - deliver
reviler - reliver
reviver - reviver
revotes - setover
rewarder - redrawer
rotanev - venator
rotator - rotator
roygbiv - vibgyor
sallets - stellas
samaroid - dioramas
seessel - lessees
sememes - sememes
sennits - stinnes
senones - senones
setover - revotes
sooloos - sooloos
stellas - sallets
stinker - reknits
stinnes - sennits
stressed - desserts
sualocin - nicolaus
sumatra - artamus
trammie - eimmart
trebled - delbert
trebloc - colbert
tressed - dessert
venator - rotanev
vibgyor - roygbiv
========================================
Loading file & sorting data: 1350 ms
Search and finding words: 341 ms
Total Time: 1691 ms
========================================

*/
