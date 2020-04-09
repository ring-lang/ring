/*
**	Application	: variables (Lists) version3
**	Author    	: Amr Ali
**	Date   		: 08/03/2018
*/
####################################################################

#list --->  Array, List, Nested List, MD List, Hash|Dict
# Number(n), List(a), String(c)

alist = []	# To Store the numbers

While True
	see "
		(1) Add Numbers
		(2) Sum Numbers
		(3) Exit

	" give cOption 

	Switch cOption

		on "1" see "Enter Number: " give cNumber aList+cNumber
			? alist 

		on "2" nSum=0 for nNum in alist nSum = nSum+nNum next 	
			? "Sum = " + nSum

		on "3" ? "You Choose To Exit Bye" bye

		other ? "Incorrect Number!"

	off 	

end













