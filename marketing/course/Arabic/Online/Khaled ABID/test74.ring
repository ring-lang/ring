/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 02/04/2018
*/

# eval() 	---> execute Ring code stored in a string 

func main

	while true
		? "Enter Expression: " give cExpr
		if lower(trim(cExpr)) = "exit"
			 exit 
		ok
		try
			? eval("return " + cExpr)
		catch
			? "Error!"
		done

	end 
