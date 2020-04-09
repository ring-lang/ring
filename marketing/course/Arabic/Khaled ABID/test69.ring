/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 01/04/2018
*/

# eval() 	---> execute Ring code stored in a string 

? "Welcome to the Ring Language" 
While true
	see "code:>" give cCode
	try
		eval(cCode)
	catch
		? cCatchError
	end
	? ""
end 
