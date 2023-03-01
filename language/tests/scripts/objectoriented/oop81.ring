aList = []

aList + new point {x=10 y=20 z=30}
aList + new point {x=100 y=200 z=300}
aList + new point {x=1000 y=2000 z=3000}
aList + new point {x=10000 y=20000 z=30000}
? aList

reverse(aList)[1] {? self x=999 y=888 z=777 ? self }

? aList
class point x y z
