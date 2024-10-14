/*  
 **      Application : Condition
 **      name        : Abdelrahman Adam
 **      Date        : 21/12/2017 
*/ 
#======================================================

#test32
# while     for      if
aList = [:one , :two , :three]
for item in aList	
			? item
		switch item	
			on :one			item = 1
			on :two			item = 2
			on :three		item = 3
			other			item = 0
		off
			? item
next

?aList
