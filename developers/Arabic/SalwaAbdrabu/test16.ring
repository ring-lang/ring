/*
**	Application : Variables (Lists) Version4
**	Author      : Salwa Abdrabu
*/

# =================================================================

# String -->(Character, Array Of Character, ML, Binary Data, NULL)
# Number -->(Int, Float|Double, Boolean(True|False))
# Lists  -->(Array, List, Nested List, MD Array)

aList = []		# To Store The Number
while true
	see "
		(1) Add Number
		(2) Sum Numbers
		(3) Exit

"	give cOption
	switch cOption 
	on "1" see "Enter Number :" give cNumber aList + cNumber 
	on "2" nSum=0 for nNum in aList nSum +=nNum next ? "Sum ="+nSum
	on "3" bye
	other ? "Bad Option!"

	off


end 
