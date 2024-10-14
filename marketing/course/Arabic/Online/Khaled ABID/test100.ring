/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 09/04/2018
*/


oRctngl = new rctngl { 
	p1 {
		x = 10
		y = 20
	}
	p2 {
		x = 100
		y = 200
	}


}

? oRctngl	# p1: Object... p2: Object...
oRctngl { ? p1 ? p2 }

class Point x y 

class rctngl
	p1 = new point 
	p2 = new point
