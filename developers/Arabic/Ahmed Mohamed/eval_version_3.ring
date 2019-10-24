/*
	Application	: Eval Version 3
	Author		: Ahmed Mohamed
	Date		: 2018/10/15
*/

#eval()	----> execute ring code stored in a string

? "Welcome to the ring programming language"

while true
	see "Code :> " give cCode
	try
		eval(cCode)
	catch
		? "Error :( " + cCatchError
	end
	? ""
end
