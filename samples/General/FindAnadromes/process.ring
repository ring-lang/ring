t1 = clock()
aList = sort(str2List(read("words.txt")))
t2 = clock()

? copy("=",40)
nMax = len(aList)
for t=1 to nMax
	if len(aList[t]) > 6 and binarysearch(aList,reverse(aList[t])) 
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
amaroid - diorama
deedeed - deedeed
degener - reneged
deified - deified
deifier - reified
deliver - reviled
dessert - tressed
desserts - stressed
deviler - relived
diorama - amaroid
dioramas - samaroid
gateman - nametag
hagigah - hagigah
halalah - halalah
kinnikinnik - kinnikinnik
leveler - relevel
murdrum - murdrum
nametag - gateman
ottetto - ottetto
pat-pat - tap-tap
peeweep - peeweep
pip-pip - pip-pip
redrawer - rewarder
reified - deifier
reifier - reifier
reknits - stinker
relevel - leveler
relever - reveler
relived - deviler
reliver - reviler
reneged - degener
repaper - repaper
reveler - relever
reviled - deliver
reviler - reliver
reviver - reviver
revotes - setover
rewarder - redrawer
rotator - rotator
sallets - stellas
samaroid - dioramas
sememes - sememes
setover - revotes
sooloos - sooloos
stellas - sallets
stinker - reknits
stressed - desserts
tap-tap - pat-pat
tat-tat - tat-tat
tat-tat-tat - tat-tat-tat
tressed - dessert
tut-tut - tut-tut
waw-waw - waw-waw
wow-wow - wow-wow
========================================
Loading file & sorting data: 298 ms
Search and finding words: 278 ms
Total Time: 576 ms
========================================
*/