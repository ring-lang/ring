/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 17/12/2017
*/
#================================================================

# eval()          ----> execute Ring code stored in a string

? "welcome to the Ring language"
while true
	see "code:> " give cCode
	eval(cCode)
	? ""
end
