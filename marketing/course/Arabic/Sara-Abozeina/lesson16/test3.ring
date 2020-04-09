/*
**	Application:reflection and meta programming
**	Author	   :Sara Abozeina
**	Date       :2018.01.03
*/
###############
/*
reflection and meta programming
*/
###############
Load "Stdlib.ring"
mergemethods(:alist1,:alist2) 	#merge methods only not attributes


new alist1
new alist2{
	op(func first,last {
				?"hello" 
				for t = first to last{
					?t
				}
			})
}

Class alist1
	x y
	op(func x,y{? x+y} )
		

class alist2
	x=1 y=5
	func op f
		call f(1,10)
