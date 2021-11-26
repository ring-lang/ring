/*
	Application	: Eval Version 5
	Author		: Ahmed Mohamed
	Date		: 2018/10/15
*/

func main

	while true
		? "Enter expression : " give cExper
		if left(lower(trim(cExper)), 4) = "exit"
			exit
		ok
		? eval("return " + cExper)
	end
