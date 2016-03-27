o1 = new point { x=10 y=20 z=30 print() }
o2 = new point { x=40 y=50 z=60 print() }
o3 = o1 + o2 
o3.print()
Class point x y z  
func print see x + nl + y + nl + z + nl 
func operator cOp,cPara
	v1 = new point
	if cOp = "+" 
		v1.x = cPara.x + x     
		v1.y = cPara.y + y      
		v1.z = cPara.z + y  
	ok
	return v1