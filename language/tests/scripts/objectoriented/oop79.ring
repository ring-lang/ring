aList = []
point = new point {x=10 y=20 z=30 }
Add(aList,point)

aList[1] { ? self x=100 y=200 ? self}
? point

? "==============="

point2 = new point {x=10 y=20 z=30 }
insert(aList,0,point2)
aList[1] { ? self x=100 y=200 ? self}
? point2

class point x y z
