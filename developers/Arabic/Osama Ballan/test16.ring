/*
**	Application  	: Variables  ( Lists) - Version4 .
**	Author 	    	: Osama Ballan .
**	Date			: 2018 - 01 - 03 .
*/

#=======================================
# Number (n)
# String (c)
# List (a)

aList = []
	while True
		see  "
			(1) Add Number
			(2) Sum Numbers
			(3) Exit
			"
		give cOption
		switch cOption
			on "1"
				see "Enter Number : "
				give cNumber
				aList + cNumber
			on "2"
				nSum = 0
				for nNum in aList
					nSum += nNum
				next
				? "Sum = " + nSum
			on "3"
				bye
			other
				see "Bad Option !!"
		off
	end
