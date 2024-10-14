/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.15
*/

# eval()	---> execute Ring code stored in a string 

func main 

	while True 
		? "Enter expression : " give cExpr 
		if left(lower(trim(cExpr)),4) = "exit"
			exit 
		ok
		? eval("return " + cExpr)
	end 
