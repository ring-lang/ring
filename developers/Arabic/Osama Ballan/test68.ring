/*
**	Application		: Ring lessons - Eval() .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 11 .
*/

# eval()		----> Execute Ring Code Stored In A String .

	? "Welcome To The Ring Language"
while true
	see "code:> " give cCode
	try
	eval(cCode)
	? ''
	catch
	? "Error !"	
	end
end


















