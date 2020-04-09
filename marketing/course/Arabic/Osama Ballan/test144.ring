/*
**	Application	: Ring lessons - Scope - Conflicts (Global - Local Variables) .
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
# Conflict Between Global Variable and Local Variable
# The Second Way To Solve The Conflict is Using Special Mark With Global Variables .
# $Global 	g_Global .

x = 10 y = 20			# x,y are Global Variables
$nSum = x + y			# nSum is Global Variable
? sum(5,6)
? $nSum

Func sum x,y			# x,y are Local Variables
	nSum = x + y		# nSum is Local Variable !
	return nSum

