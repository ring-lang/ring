myvar = :what
? myvar
myvar = myfunc(myvar, new point)
? myvar
myvar = new point {x=10 y=20 z=30}
? myvar
myvar = myfunc(new point,myvar)
? myvar
myvar = myfunc2(myvar,new point,myvar,new point)
? myvar

func myfunc a,b
	return 10

func myfunc2 a,b,c,d
	return 20

class point x y z 