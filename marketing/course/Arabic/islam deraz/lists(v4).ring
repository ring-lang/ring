/*
**          Application         : Variables (lists version 4)
**          Author              : Islam Deraz
**          Date                : 2018.02.03
**          Application Number 	: 8
*/ 

#========================================

# number (n)
# list (a)
# string (c)

alist = []			# to store the numbers

while True
			see "
					(1) Add Number
					(2) Sum Numbers
					(3) Exit

				"
			give cOption
		    switch cOption
				on "1" see "Enter Number: "  give cNumber    alist + cNumber
				on "2" nsum = 0 for nNum in alist     nsum = nsum + nNum Next
						? "Sum = " + nsum
				on "3" bye 							# shutdown
				other ? "Bad option!"

				off

end

