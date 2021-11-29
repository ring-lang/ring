/*
**	Application 	: Choose number and enter it by keyboard-number -version2
**	Author		: Sara Abozeina
**	Date		: 2017.12.16	
*/

see  "please , Enter your name" + nl	Give cName
see  "please , Enter number from list " + nl		
?       " [0,1,2] "
Give nId
nId=0+nId

if random(2)=nId
	?  "Good Luck , "+ cName 
else
	? "sorry , bad luck"
ok

