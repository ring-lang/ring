func main
	o1 = new screen  {
		content[point()] { 
			x = 100 
			y = 200
			z = 300		
		}
		content[point()] { 
			x = 50 
			y = 150
			z = 250		
		}
	}
	see o1.content[1]
	see o1.content[2]

Class Screen
	content = []
	func point
		content + new point
		return len(content)

Class point 
	x  = 10
	y  = 20
	z  = 30