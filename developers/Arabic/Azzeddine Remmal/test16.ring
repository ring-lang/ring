#############################################
# Application : Variables (Lists)
# Author      : Azzeddine Remmal            
# Date        : 05.01.2018                  
####################################



#----------------- Number (n)
#------------------ List (a)
# ------------------String (c)

aList = []		                        # ------To store the numbers 

While True 
	see "
			(1) Add Number 
			(2) Sum Numbers 
			(3) Exit
	" give cOption
	switch cOption 
		on "1" see "Enter Number : " give cNumber aList+cNumber
		on "2" nSum=0 for nNum in aList nSum = nSum+nNum next 
			? "Sum = " + nSum
		on "3" bye
		other ? "Bad option!"
	off
end
