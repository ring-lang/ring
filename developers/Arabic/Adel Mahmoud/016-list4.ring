/*
**	Application		:variables (Lists4)
**	Author			:Adel Mahmoud
**	Date			:2018.01.28
*/

#=========================================================

# shortcuts
# Numbers ---> n
# Strings ---> c (Character)
# Lists   ---> a

#=========================================================
load "stdlib.ring"
aList = []		# to store numbers in it		

While True

see "
	(1) Add Numbers
	(2) Sum Numbers
	(3) Exit
" give cOption

	switch cOption
		on "1" see "Enter Number : " give cNumber aList+cNumber
		on "2" nSum=0 for nNum in aList nSum=nSum+nNum 
			      next
			see "Sum = " +nSum
		on "3" ? "good bye"  sleep(2) bye
		other see "Bad option"
	
	off

end

#=========================================================



