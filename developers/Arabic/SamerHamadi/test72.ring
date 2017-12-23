/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 20/12/2017
*/
#================================================================

func main 
	
	while true
		? "Enter Expression :" give cExpr
		if lower(trim(cExpr)) = "exit"
			exit
		ok
		try	
			? eval("return " + cExpr)
		catch
			? "Error!"
		done
	end
		
