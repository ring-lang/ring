/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

# eval ---> execute Ring code stored in a string

 func main 

	while true

		? "Enter Your Expression:" give cExpr
		if left(lower(trim(cExpr)),4) = "exit"
		exit
		ok
		? eval("return " + cExpr)
	end
	
