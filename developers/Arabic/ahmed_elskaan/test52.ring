/*
**	Application Name : eval();
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-18;		
*/
? "welcome to ring"
while true
	see "code:> " give test
	try
		eval(test)
	catch
		? "error!"
	end
	? ""
end
