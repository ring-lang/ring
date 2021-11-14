// Binary Search
// Bert Mariani 2020-010-05
//
// Binary search is an efficient algorithm for finding an item from a sorted list of items. 
// It works by repeatedly dividing in half the portion of the list that could contain the item, 
// until you've narrowed down the possible locations to just one.
//


aList  = [18, 1, 21, 0, 11, 15, 2, 9, 3, 13, 10, 7, 6, 14, 5, 22, 17, 25]  // Random 0-25 Size 18
maxNbr = 25

//----------------------------------
Func main()

   //-------------------------------------------
	// START with a random List with Holes in it
	
   See "Random aList: "+nl   display1D(aList)

   //--------------------------------------------------
	// MUST be SORTED  Before for Binary Search to Work 
	
   aList = sort(aList)
	See "Sorted aList: "+nl   display1D(aList)

   //----------------------
	// Find random numbers
	
	for i = 1 to maxNbr

		nbr = random(maxNbr)             // Find this Nbr = 0 to 25
		See  nl+nl+"Find: "+ nbr +nl     
		
		p   = binarySearch(aList, nbr)   //===>>> CALL
		
		if p = -1
			See "Search: NOT Found at Position: "+p  +" Value: "+ nl
		else
			See "Search: Found at Position: "+p  +" Value: "+ aList[p] +nl
		ok
	next

return

//----------------------------------
// Return Position found => Value
// Return -1 NOT Found

Func binarySearch(nums, target) 
	start = 1            // Ring Index
	last  = len(nums)

	while start <= last

		p = floor((start + last) / 2)
				See "     P: Start: "+ start +" Last: "+ last +" P: "+ p +nl
	 
		if nums[p] = target 
			return p
			
		but target < nums[p]
			last = p - 1

		but target > nums[p] 
			start = p + 1
		ok
		
	end
  
return -1   // "NotFound"

###-------------------------------------------
### Generate a Random List, Size and Unique

Func RandomUniqueList(size)

    aInput = 1:size       // List create
	 
	 See "Unique aInput: Size: "+ size +nl   display1D(aInput)
	 
    aOutput = []

    while len(aInput) > 1
        nIndex = random(len(aInput)-1)
        nIndex++

        aOutput + aInput[nIndex]
        del(aInput,nIndex)
    end

    aOutput + aInput[1]
return aOutput

//============================

Func display1D(array)

   size = len(array)
   
   for i = 1 to size
      See " "+ array[i]
   next
   See nl+nl

return

//-----------------------------

Func display2D(array)

   sizeX = len(array)
   sizeY = len(array[1])
   
   for i = 1 to sizeY
      See "...: "+i +" > "
      for j = 1 to sizeX
         See " "+ array[i][j]
      next
      See nl
      
   next
   See nl+nl

return

 
//------------------------------------
