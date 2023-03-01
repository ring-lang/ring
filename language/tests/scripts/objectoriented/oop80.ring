aList = []

aList + new point {x=10 y=20 z=30}
aList + new point {x=100 y=200 z=300}
aList + new point {x=1000 y=2000 z=3000}
aList + new point {x=10000 y=20000 z=30000}
? aList

aList2 = reverse(aList)
? aList2

for t=1 to 4
	aList[t] { x=t y=t z=t ? self}
next
? aList

? aList2[1] { ? self x=999 y=888 z=777 ? self }

for t=1 to 4
	aList[t] { x=t y=t z=t ? self}
next

class point x y z
