#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 10.01.2018                  
####################################

#--------------eval()---> execute Ring code stored in a string 

func main 

	while True 
		? "Enter expression : " give cExpr 
		if left(lower(trim(cExpr)),4) = "exit"
			exit 
		ok
		? eval("return " + cExpr)
	end 
