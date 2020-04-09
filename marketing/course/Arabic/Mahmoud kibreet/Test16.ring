/*
          Application : Variables(Lists) - version4
          Author      : Mahmoud Kibreet
          Date        : 2018.01.23
*/

#=============================================================
# Number (n)
# List (a)
# String (c)

aList = []

while True 
	see"

	(1) Add Number
	(2) Sum Numbers
	(3) Exit
	"give cOption
	 switch cOption
		on "1" see "Enter Number : " give cNumber aList + cNumber
		on "2" nSum=0 for nNum in aList nSum = nSum + nNum next
		? "Sum = " + nSum
		on "3" bye
		other ? "Bad Option!"
        off 

end 
