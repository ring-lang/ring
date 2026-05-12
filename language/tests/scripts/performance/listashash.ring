aList = [1,2,3,4,5]

for t=1 to 100
	aList + [ "key"+t , t*t ]
next

? aList["key1"]
? aList["key10"]
? aList["key100"]

del(aList,50)
aList + 1000

aList[10] = NULL
del (aList[11],2)
del (aList[12],1)

// =============================================
// Performance Test
// =============================================
t1 = clock()
for m=1 to 1_000_000
	aList["key1"]
	aList["key10"]
	aList["key100"]
next
t2 = clock()
// =============================================

? "================"
? aList
? "================"
? aList["key1"]
? aList["key10"]
? aList["key100"]
? "================"
? aList[105]
? aList[1]
? aList[2]
? aList[3]
? aList[4]
? aList[5]
? "================"
if (t2-t1)/clocksPerSecond() < 1
	? "Performance Test: Pass"
else
	? "Performance Test: Fail"
ok
? "================"