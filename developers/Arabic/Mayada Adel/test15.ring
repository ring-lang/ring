# ------------ Variables (Lists) Part 3 ------------
# ------------         Example          ------------
aList = []  # Empty List To Store Number
While True
	see	
	"
		(1) Add Number		
		(2) Sum Numbers
		(3) Exit	
	"
	give cOption
	switch cOption
		on "1" See "Enter Number" Give cNumber aList + cNumber
		on "2" nSum = 0 for nNum in aList nSum = nSum + nNum next
			? "Sum = " + nSum
		on "3" bye
		other ? Bad Option
	Off
end
