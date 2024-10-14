# بسم الله الرحمن الرحيم
// this is Lesson8 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  function:Eval()
  Author     :  S.BOURROU
  Date       :  20.12.2017  
*/


func main
	while true
		? ""
		? "Enter an Expression:"
		give cExp
	 	if left(lower(trim(cExp)),4) = "exit"
		exit 
		ok
		see Eval("return " + cExp)

	

	end
