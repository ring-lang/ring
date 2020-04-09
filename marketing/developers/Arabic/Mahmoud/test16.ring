/*
**	Application 	: Variables (Lists) - version 4
**	Author		: Mahmoud Fayed
**	Date		: 2017.12.10
*/

#===============================================================
# Number (n)
# List (a)
# String (c)

aList = []		# To store the numbers 

While True 
	see "
			(1) Add Number 
			(2) Sum Numbers 
			(3) Exit
	" give cOption
	switch cOption 
		on "1" see "Enter Number : " give cNumber aList+cNumber
		on "2" nSum=0 for nNum in aList nSum = nSum+nNum next 
			? "Sum = " + nSum
		on "3" bye
		other ? "Bad option!"
	off
end
