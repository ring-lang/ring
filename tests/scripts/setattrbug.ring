o1 = new container
o1.alist + new point
o1.alist + new point

o2 = new point
see o1.alist[1].x + nl
see (100 + o1.alist[1].x) + nl
o2.x = 100 + o1.alist[1].x
#vvalue = 100 + o1.alist[1].x
#o2.x = vvalue
see o2.x + nl
see "print obj" + nl
see o1
#see o1.alist[1]

class point x y
	x = 10
	y = 20
	
class container
	alist = []
