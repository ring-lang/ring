/*  
 **      Application : for
 **      name        : Abdelrahman Adam
 **      Date        : 21/12/2017 
*/ 
#======================================================

#test33
# while     for      if
aList = [:one , :two , :three]
for item in aList	
			? item
		switch item	
			case :one		item = 1
			case :two		item = 2
			case :three		item = 3
			else			item = 0
		end
			
end

?aList
#======================================================
aList = [:one , :two , :three]
for item in aList	{
			? item
		switch item{	
			case :one		item = 1
			case :two		item = 2
			case :three		item = 3
			else			item = 0
		}
			
}

?aList
