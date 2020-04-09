/*
**  Application: Variables (Lists) - version4
**  Author     : Ahmed Khalifa
**  Date       : 2017.12.11
*/
#=========================================================================================

# list	---> Array, List, Nested List, MD Array
# Example
 alist = []						# to store the numbers
while True 
	see "						# message For the user 

		(1) Add Number 	
		(2) Sum Numbers
	 	(3) Exit

	    " give cOption				# the user enter the option 
	      switch cOption
			on "1" ? "Enter Number : "	give cNumber  aList+cNumber
			on "2" nsum=0 for nNum in alist nsum = nsum+nnum next
			? "sum = " + nsum
			on "3" bye
			other ? "Bad Option :("
		off
end


#=========================================================================================


#=========================================================================================
