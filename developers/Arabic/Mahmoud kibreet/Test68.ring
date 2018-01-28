/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.28
*/

# eval             # execute Ring code stored in a string 

? "welcome to the Ring language"
while True
	see "code:> " give cCode
	try 
		eval(cCode)
	catch
		? "Error!"
	end
	? ""
end 
