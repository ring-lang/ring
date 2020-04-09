# بسم الله الرحمن الرحيم
// this is Lesson9 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  function:Eval()
  Author     :  S.BOURROU
  Date       :  25.06.2018  
*/


func main
	while true
		? ""
		? "Enter an Expression:"
		give cExp
	 	if lower(trim(cExp)) = "exit"
		exit 
		ok
		try
		see Eval("return " + cExp)
		catch
			? "ERROR!"
		done			

	

	end
