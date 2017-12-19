/*
**	Application    : variables (lists) -version4 
**	Author 	       : Samer Hammadi
**	Date           : 14/12/2017
*/
#================================================================

alist = []

while true
	see "
		(1)Add Number
		(2)Sum Numbers
		(3)Exit
	"give cOption
	switch cOption
		on "1" see "Enter number: " give cNumber alist+cNumber
		on "2" nSum=0 for nNum in alist nSum=nSum+nNum next
			? "Sum = " + nSum
		on "3" bye
		other	? "Bad Option!!"
	off






end




	   
