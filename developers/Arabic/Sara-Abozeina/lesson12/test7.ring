/*
**	Application:object-oriented
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
########
/*
objects overloading
*/
########

sq=new square {
	sh1{
		x=10 y=10
	}
	sh2{
		x=40 y=40
	}
}

orec=new rect{
	r1{
		x=10 y=50
	}
	r2{
		x=20 y=40
	}
}

?sq.sh1 
?sq.sh2
?orec.r1
?orec.r2
class square
	sh1=new draw
	sh2=new draw
class rect
	r1=new draw
	r2=new draw

class draw
	 x y
	 
