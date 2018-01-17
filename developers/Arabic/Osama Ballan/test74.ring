/*
**	Application	: Ring lessons - Eval() .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 12 .
*/

# eval()		----> Execute Ring Code Stored In A String .

func main
	while True
		? "Enter Expression : " give cExpr
		if lower(trim(cExpr)) = "exit"
			exit
		ok
		try
			? eval("return " + cExpr) 
		catch
			? "Error !"
		done
	end


















