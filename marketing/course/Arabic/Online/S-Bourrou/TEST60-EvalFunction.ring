# بسم الله الرحمن الرحيم
// this is Lesson8 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  function :Eval(),cCatchError
  Author     :  S.BOURROU
  Date       :  19.12.2017  
*/

 # execute ring code stored in a string using eval function

	? eval("see 'HELLO!' ")


# execute code input
? "Enter a code "
while true 
	? "Code:>" give cCode
	try
	eval(cCode)
	catch 
	? cCatchError  # or print any message ? msg
	end
	? ""
end
