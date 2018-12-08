/*
**	Application 	: Variables (Lists) Version 4
**	Author 	    	: Ahmed Mohamed
**	Date	    	: 2018/12/8
*/

#==================================================
# Number (n)
# List (a)
# String (c)

aList = [] // To Store The Numbers 

while True
	See "
		(1) Add Numbers
		(2) Sum Numbers
		(3) Exit	
	" Give cOption 
	switch cOption
		on "1" see "Enter Number " give cNumber aList + cNumber
		on "2" nSum = 0 for nNum in aList nSum = nSum + nNum next
			? "Sum = " + nSum
		on "3" bye
		other ? "Bad Option"		
	
	off
end


