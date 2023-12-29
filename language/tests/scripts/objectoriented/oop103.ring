p1  = new point
? p1
p2 = (new point)
? p2
p3 = (new point { x=10 y=20 z=30 })
? p3
? p3.more() {x=100 y=200 z=300}
p4 = (new point) { x=1000 y=2000 z=3000 }
? p4

try
	p5 = ( 5 ) { x=10 y=20 z=30 }
catch
	? "Pass The Error!"
done

class point x y z

	func more
		return new point