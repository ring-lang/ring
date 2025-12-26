new point {
	x=10 y=20 z=30
	cFunc = func { 
		? "x = " + x
		? "y = " + y
		? "z = " + z
	}
	call { cFunc() }
}

class point x y z