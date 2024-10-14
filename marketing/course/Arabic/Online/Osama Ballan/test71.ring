/*
**	Application		: Ring lessons - Eval() .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 11 .
*/

# eval()		----> Execute Ring Code Stored In A String .

func main
	while True
		? "Enter Expression : " give cExpr
		if left(lower(trim(cExpr)),4) = "exit"
			exit
		ok
		? eval("return " + cExpr) 
	end


















