/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 01/04/2018
*/

# eval() 	---> execute Ring code stored in a string 

func main

	while true
		? "Enter Expression: " give cExpr
		if left(lower(trim(cExpr)),4) = "exit"
			 exit 
		ok
		? eval("return " + cExpr)
	end 
