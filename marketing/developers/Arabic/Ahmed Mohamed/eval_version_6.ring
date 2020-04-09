/*
	Application	: Eval Version 5
	Author		: Ahmed Mohamed
	Date		: 2019/10/24
*/

func main

	while true
		? "Enter experssion : " give cExper
		if lower(trim(cExper)) = "exit"
			exit
		ok
		try
			? eval("return " + cExper)
		catch
			? "Error ! "
		done
	
	end
