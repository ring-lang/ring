/*
**	Application	: Variables (Lists) - version 4
**	Author		: Khaled ABID
**	Date		: 19/12/2017
*/

#=====================================================================
# Number(n)
# List(a)
# String(c)

alist = []	# Empty List to store the numbers

While True
	see "

		(1) Add Number
		(2) Sum Numbers
		(3) Exit

	" give cOption
	switch cOption
		on "1" see "Enter Number: " give cNumber aList+cNumber
		on "2" nSum=0 for  nNum in aList nSum = nSum+nNum next
			? "Sum = " + nSum
		on "3" bye 	# shutdown()
		other ? "Bad option!"
	off


end
