/*
**	Application Name : variables (List app);
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-11;		
*/
#================================================

aList = []

while True
	see "
		(1) Add number
		(2) Sum numbers
		(3) Exit
	" give cOption
	switch cOption
	      on "1" see "Enter Number: " give cNumber aList+cNumber
	      on "2" nSum = 0 for nNum in aList nSum+=nNum next
                       ? "Sum = "+nSum
	      on "3" bye	
	      other ? "bad choice"
	off
end




