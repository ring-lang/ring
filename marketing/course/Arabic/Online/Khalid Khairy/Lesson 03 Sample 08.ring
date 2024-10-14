/*
**	Application : Variables(Lists) v.04
**	     Author : Khalid Khairy
**	       Date : 14/12/2017
*/

#===================================================
aList = []

while true
	see"
		(1) Add Number 
		(2) Sum Numbers
		(3) Exit
	   "
	give cOption
		switch cOption
			on "1" see "Enter Number : " give cNumber aList+cNumber
			on "2" nSum=0 for nNum in aList nSum+=nNum next 
				? "Sum = " + nSum
			on "3" shutdown() # bye
			other ? "Bad Option"
		off
end	
