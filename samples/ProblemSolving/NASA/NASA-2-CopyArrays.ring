# Project: Copy Array
# Date   : 2018/07/08
# Author : Bert Mariani
#
# NASA -Problem 2: Copy Arrays


Load "stdlib.ring"

Puts("Test CopyArray(), N=5000, 7000, 9000 ")
Puts("")

###-------------------------------
### Build a Matrix size: n x n X 3
###-------------------------------

n = 1000

###---------------------------------------------------------
### Create Array -- Dimensions Any Size:  3D, 4D, 5D etc

See "Start build... array of Dim: "+ n +" "+ n +" "+ 3 
startTime = clock()

	dimList = [n,n,3]
	bList   = createDimList(dimList)

endTime   = clock()
diffTime  = endTime - startTime
See Tab +" --- End build... array: "+ n  +" Time-msec: "+ diffTime +nl

###------------------------------------------------------------------------
### Populate the arrays using a counter 1 ,  4x4x4 = 256 , 2x3x4x5x6 = 720

See "Start populate array of Dim: "+ n +" "+ n +" "+ 3 
startTime = clock()

	Counter = 1

	for Col=1 to dimList[1]
	  for Row=1 to dimList[2]
		for Dep=1 to dimList[3]
				blist[Col][Row][Dep] = Counter
				Counter++
		next
	  next
	next

endTime   = clock()
diffTime  = endTime - startTime
See Tab +" --- End populate array: "+ n  +" Time-msec: "+ diffTime +nl

###-----------------------------------------------
### Before: Print the array elements in block format

/*
	for Col=1 to dimList[1]
	  for Row=1 to dimList[2]
		for Dep=1 to dimList[3]
				See bList[Col][Row][Dep] See " "
		next
			See nl
	  next
		See nl
	next
*/

###------------------------------------------------------------------------
### Copy the arrays using a counter 1 ,  4x4x4 = 256 , 2x3x4x5x6 = 720

See "Start copy.... array of Dim: "+ n +" "+ n +" "+ 3 
startTime = clock()

	Counter = 1

	for Col=1 to dimList[1]
	  for Row=1 to dimList[2]
	  
				blist[Col][Row][1] = blist[Col][Row][2]
				blist[Col][Row][3] = blist[Col][Row][1]
				blist[Col][Row][2] = blist[Col][Row][3]
				Counter++
				
				### See "Copy: 1: "+ blist[Col][Row][1] +" 3: "+ blist[Col][Row][3] +" 2: "+ blist[Col][Row][2] +nl

	  next
	next

endTime   = clock()
diffTime  = endTime - startTime
See Tab +" --- End copy.... array: "+ n  +" Time-msec: "+ diffTime +nl
	
###-----------------------------------------------
### After: Print the array elements in block format

/*
	for Col=1 to dimList[1]
	  for Row=1 to dimList[2]
		for Dep=1 to dimList[3]
				See bList[Col][Row][Dep] See " "
		next
			See nl
	  next
		See nl
	next
*/


###===========================
### FUNCTIONS

###-----------------------------------------------------------------------
### Recursive Create a Dimension Array
### Call by passing an array of dimensions: dimList = [2,3,4,5]
### Drop the first entry every iteration call, making newParms
###
### Example:
###    dimList = [4,2,3,2]                <<< Number and size of dimensions in array format
###    bList   = createDimList(dimList)   <<< Call using the array as input

func createDimList(dimArray)

     sizeList = len(dimArray)

     newParms = []
     for i = 2 to sizeList
        Add(newParms, dimArray[i])
     next

     alist = list(dimArray[1])

     if sizeList = 1
        return aList
     ok

     for t in alist
         t = createDimList(newParms)
     next

	 
return alist

###----------------------------------------------------
