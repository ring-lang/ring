#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 10.01.2018                  
####################################

# ----------eval()	-------------> execute Ring code stored in a string 

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
