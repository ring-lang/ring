/*
**	Application	: operations on list
**	Author		: Sara Abozeina
**	Date			: 2017.12.16	
*/

# Load Standard Libraries
Load "stdlib.ring"

sum=0	
alist=[]


while true
	
	see" (1) Continue
		(2) Show result	
		(3) Edit
		(4) Clear	
		(5) Exit
		"	Give cOption
			
	switch cOption
	
			on 1
				?"Add Numbers"	give cNums	nNums=0+cNums	
				alist=alist+nNums	
			on 2 
				sum=0
				for x in alist
					sum=sum+x
				next	
				?"sum  of list items = " + sum

			on 3 
				?"the list items :" see alist
				?"enter the index of  item you want to delete it"	
				give  cdelete	ndelete=0+cdelete
				alist[ndelete]=null

			on 4
				alist=[]
				sum=0	
				loop
				
			on 5
					exit
	
			other
				? 'Bad option,try again'
		
	off
end
