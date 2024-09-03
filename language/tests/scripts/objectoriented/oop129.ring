m=1
m = mytest(new point(m))
? m

new myclass {
	v=2
	v = mytest(new point(V))
	? v
}

new myclass2

new myclass3

func mytest para
	return :good

class myclass

class myclass2
	v=3
	v = mytest(new point(V))
	? v

class myclass3
	new myclass {
		v=4
		v = mytest(new point(V))
		? v
	}

class point
	func init para
		? para	