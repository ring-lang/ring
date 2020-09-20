### RadixSort
### Ring uses index 1 so adjusted  index 0 => 1
###
### Info at:
### https://www.programiz.com/dsa/counting-sort
### https://www.programiz.com/dsa/radix-sort
###
### Bert Mariani 2020/09/19


###---------------------------------------------------
 
Func main()

   arr = [82,901,100,12,150,77,3145,2687,55,23]
	n   = len(arr)
   
   See "Initial array: "+nl
   print(arr, n) 
 
	radixsort(arr, n);
 
   See "------------"+nl+nl
   See "Final array: "+nl
   print(arr, n)
      
return 0

###---------------------------------------------------  
// Sort arr[] of size n using Radix Sort.

Func radixsort(arr, n)
   
	m      = getMax(arr, n)  
   digits = len(""+ m)  
 
	// Calling countSort() for digit at (place)th place in every input.
   
   place = 1
	for i = 0 to digits - 1 
      
      See "------------"+nl+nl
      See "Place: "+ place +nl
      
		countSort(arr, n, place)
      place = place * 10

   next

return



###--------------------------------------------------- 
// CountSort method of arr[].

Func countSort(arr, n, place)

	// Count[i] array will be counting the number of array values having that 'i' digit at their (place)th place.  
	output = list(n) 
   count  = list(11)  
 
	// Count the number of times each digit occurred at (place)th place in every input.
	for i = 1 to n
      here = floor((arr[i] / place) % 10)
		count[  here +1] += 1    // ++;
   next
 
	// Calculating their cumulative count.
	for i = 2 to 10;             // 1
		count[i] += count[i-1];
   next
          
	// Inserting values according to the digit '(arr[i] / place) % 10' fetched into count[(arr[i] / place) % 10].
	for i = n to 1 step -1     
	
      here = floor((arr[i] / place) % 10 +1)      
		output[ count[ here ] ]  = arr[i]
		        count[ here ]   -= 1
	next
   
   arr = output

   See "arr Sort: "+nl
   print( arr,  n)
            
return      

 
###---------------------------------------------------  
// Get maximum value from array

Func getMax( arr, n)
	mx = arr[1]
	for i = 1 to n
		if (arr[i] > mx)
			mx = arr[i]
      ok
   next
return mx

###---------------------------------------------------   
// A utility function to print an array 

Func print(arr, n) 
 
    for i = 1 to n 
        See " | "+ arr[i] 
    next 
    See nl+nl
    
return


###--------------------------------------------------- 
// Sorted Data ->1->3->12->54->96->129->542->886->1125->3125
