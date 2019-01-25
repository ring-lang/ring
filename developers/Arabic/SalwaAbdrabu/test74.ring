/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

# eval ---> execute Ring code stored in a string

 func main 
	while true
		? "Enter Your Expression:" give cExpr
		
		if lower(trim(cExpr)) = "exit"
			exit
		ok

		try
		eval("return" + cExpr)
		
		catch
		? "Error!"

		end
	end

	
