# variables types 
/*
 * Application       : variables lists ver4
 * Author            : Hany Ibrahim Ahmed
 * Date              : 18/12/2017
 */

# variables types (string,number,list,object,c object)

# list -> array, list, nested, nested list, MD array, Hash Dict

alist=[]	# to store the numbers
while true
		see"
			(1) add numbers
			(2) sum numbers
			(3) Exit
		"give cOption
			switch cOption
			on "1" see "enter number: " give cnumber alist+cnumber
			on "2" nsum=0 for nNum in alist Nsum=Nsum+Nnum next
			? "sum= :" + nsum
			on "3" exit
			other ? "Bad option!"
			
			off
end
