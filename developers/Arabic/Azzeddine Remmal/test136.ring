###################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 24.01.2018                  
###################################

load "stdlib.ring"


#--------------Reflection & Metaprogramming


mergemethods(:list,:mylist)

oList = new list( [1,2,3] )
oList.print()
? "Size : " + oList.size()
? "Size : " + oList.count()

class mylist 
	func count 
		return len(vValue)
