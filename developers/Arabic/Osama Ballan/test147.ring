/*
**	Application	: Ring lessons - Scope - Conflicts (Global - Class Attribute) .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 25 .
*/

/*
			Variables Scope
			Three Scopes :
			(1) Global Scope
			(2) Object Scope
			(3) Local Scope
*/
# Conflict Between Global Variable and Class Attribute
$x = 100
new point {
	x = 10 y =20 ? self
}
Class point 
		x y		# We Expected x,y To Be Object Attributes .
