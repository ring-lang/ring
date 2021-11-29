/*
**	Application 	: Choose number and enter it by keyboard-put and get
**	Author		: Sara Abozeina
**	Date		: 2017.12.16	
*/

put "please , Enter your name" + nl	get cName
put  "please , Enter number from list " + nl		
?       " [0,1,2] "
get nId
nId=0+nId

if random(2)=nId
	?  "Good Luck , "+ cName 
else
	? "sorry , bad luck"
ok

