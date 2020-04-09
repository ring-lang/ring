#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 20.01.2018                  
####################################



oRect = new rect {
	p1 {
		x = 10
		y = 20
	}
	p2 { 
		x = 100
		y = 200
	}
}

oRect { ? p1 ? p2 }

class point x y

class rect 
	p1 = new point 
	p2 = new point 
