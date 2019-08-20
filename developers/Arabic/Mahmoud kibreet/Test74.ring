/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.29
*/

# eval             # execute Ring code stored in a string 

func main 

	while True
		? "Enter expression :" give cExpr
		if lower(trim(cExpr)) = "exit" 
		exit 
		ok
			try 
				? eval("return " + cExpr)
			catch 
				? "error!"
			Done	
	end 
