#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 10.01.2018                  
####################################

# --------------eval()-------> execute Ring code stored in a string 

? "Welcome to the Ring language"
While True 
	see "code:> " give cCode 
	Try
		eval(cCode)
	catch 
		? "Error!" 
	end 
	? ""
end	
	
