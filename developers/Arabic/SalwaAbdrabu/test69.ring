/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

# eval ---> execute Ring code stored in a string

? "Welcome To The Ring Language"
while true
	
	? "Enter Your Code >" give cCode
	try
	eval (cCode)
	
	catch 
	? cCatchError
	end
	? ""
end  
	
