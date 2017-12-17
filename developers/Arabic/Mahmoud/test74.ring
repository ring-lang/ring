/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.15
*/

# eval()	---> execute Ring code stored in a string 

func main 

	while True 
		? "Enter expression : " give cExpr 
		if lower(trim(cExpr)) = "exit"
			exit 
		ok
		Try
			? eval("return " + cExpr)
		catch 
			? "Error!"
		Done
	end 
