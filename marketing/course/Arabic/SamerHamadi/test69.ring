/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 17/12/2017
*/
#================================================================

# eval()          ----> execute Ring code stored in a string


	while true
		? "Enter expression : " give cExpr
		if left(lower(trim(cExpr)),4) = "exit"
		   	exit
		ok
		? eval("return "+ cExpr)
	
	end
