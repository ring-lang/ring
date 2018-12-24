new point {x=10 y=20 z=30 start() }
class point x y z
	func start
		see self # print the x y z values (10,20,30)
		new Local {
			x = 100
			y = 200
			z = 300
		}
		see self # print the x y z values (10,20,30)	
		see x + nl # will print 100
		see y + nl # will print 200
		see z + nl # will print 300
		Self {	# NO Advantage - Search is done in local scope first
			see x + nl # will print 100
			see y + nl # will print 200
			see z + nl # will print 300
		}
		see self.x + nl # will print 10
		see self.y + nl # will print 20
		see self.z + nl # will print 30

	
class Local