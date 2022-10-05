###---------------------------------------------------------------------------
### Create Array -- Dimensions Any Size:  3D, 4D, 5D etc

dimList = [2,3,4,5,6,7]
bList   = createDimList(dimList)


###-----------------------------------------------------
### Populate the arrays using a counter 1 
### .... 4x4x4x4   => 256
### .... 2x3x4x5x6 => 720

Counter = 1

for Col=1 to dimList[1]
  for Row=1 to dimList[2]
    for Dep=1 to dimList[3]
      for Elm=1 to dimList[4]
        for Fox=1 to dimList[5]
          for Geo=1 to dimList[6]

            #See "|"+ Col +"|"+ Row +"|"+ Dep +"|"+ Elm +"|"+ Fox +"|"+ Geo +"| == "+ Counter +nl
            blist[Col][Row][Dep][Elm][Fox][Geo] = Counter
            Counter++

          next 
             #See nl
        next 
           #See nl
      next
         #See  nl
    next
       #See   nl
  next 
     #See  nl
next

###-------------------------------------------------------
### Print the array elements in block format

See nl+nl+"============"+ nl+nl

for Col=1 to dimList[1]
  for Row=1 to dimList[2]
    for Dep=1 to dimList[3]
      for Elm=1 to dimList[4]
        for Fox=1 to dimList[5]
          for Geo=1 to dimList[6]

            See bList[Col][Row][Dep][Elm][Fox][Geo] See " "

          next
             See nl
        next
           See nl
      next
         See "++++++++++"+ nl +nl
    next
         See ".............."+ nl +nl
  next 
         See "-----------------"+ nl +nl
next

###===========================
### FUNCTIONS

###------------------------------------------------------------------------------------------------------------------
### Recursive Create a Dimension Array 
### Call by passing an array of dimensions: dimList = [2,3,4,5]
### Drop the first entry every iteration call, making newParms
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

