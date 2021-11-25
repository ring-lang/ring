/*  
 **      Application : variables (lists), version4
 **      Author        : Abdelrahman Adam
 **      Date        : 20\12\2017 
*/ 
#======================================================

# variables type ( string , number , list , object , cobject )

# test16

alist =  [ ]

while true
    		  see " 
				(1) Add number
				(2) Sum numbers
				(3) Exit
			"
			give cOption
			switch cOption
						on "1" ? "Enter number : " give cNumber Add(alist, cNumber)
						on "2" nsum=0 for x in alist nsum = nsum + x next
							? "sum : " + nsum
						on "3" bye
						other ? "Bad Option"

				off
end
