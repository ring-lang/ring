/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.15
*/

# eval()	---> execute Ring code stored in a string 

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
	
