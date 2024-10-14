/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.30
*/

new point { 
	x = 10 y = 20 
	print() 
       ? x
}


class point 

	x y          # Public  

	func print 
		? "X : "  + X + 
		" Y : " + Y
  
func getx 
	? "Message from Getx()"
	return x

func setx value 
	x = value + 10
	? "Message from setx()"
