###----------------------------------------------------------------------
### Create Array -- Dimensions Any Size:  3D, 4D, 5D etc (Really a LIST)
### There are 3 Ways to Call |  Populate and Display  

// First
   aDim   = [3,4,5,6]                  // 1- Multi-Dim-Array of Rows, Cols, Blocks
   mArray = newArray(aDim)             // 2- Create the Multi-Dim-Array (Really a LIST))
   
   Populate(aDim)
   See "Print aDim: 3,4,5,6: "+nl  Print(aDim)
  
// Second  
   mArray = newArray([6,5,4,3])        // 1- Populate array using number indexes
   
   Populate([6,5,4,3])
   See "Print [6,5,4,3]: "+nl   Print([6,5,4,3])
   
// Third 
   a=4  b=3  c=6  d= 5                 // 1- Assign number to letter
   mArray = newArray([a,b,c,d])        // 2- Populate array using letter reference to indexes
   
   Populate([a,b,c,d])
   See "Print [a,b,c,d] 4,3,6,5: "+nl   Print([a,b,c,d])   
   
###---------------------------------------------------------------------
### Populate the arrays. Uses aDim[]  4x4x4 = 256 , 2x3x4x5x6 = 720

Func Populate(aDim)

   Counter = 1

   for i=1 to aDim[1]                               // a // 3 // aDim[1]
     for j=1 to aDim[2]                             // b // 4 // aDim[2]
       for k=1 to aDim[3]                           // c // 6 // aDim[3]
         for m=1 to aDim[4]
               mArray[i][j][k][m] = Counter
               Counter++
         next
       next
     next
   next
return

###-----------------------------------------------------------------------
### Print the array elements in block format. Uses aDim[]

Func Print(aDim)
 
   for i=1 to aDim[1]                                 // a // 3 // aDim[1]
     for j=1 to aDim[2]                               // b // 4 // aDim[2]
       for k=1 to aDim[3]                             // c // 6 // aDim[3]
         for m=1 to aDim[4]                           // d
               See mArray[i][j][k][m]  See " "
         next
         See nl
       next
       See nl
     next
     See nl
   next
return

###-----------------------------------------------------------------------
### Recursive Create a Multi-Dimension Array (List)
### Call by passing an array of dimensions: dimList = [3,4,5,6]
### Drop the first entry every iteration call, making newParms
###
### Example:
### Create Array -- Dimensions Any Size:  3D, 4D, 5D etc
### 3 Ways to Call, Populate and Display 
###
### First
### aDim   = [3,4,6]              // 1- multi-dim-Array of Rows, Cols, Blocks
### mArray = newArray(aDim)       // 2- Create the multi-dim-Array (List)
###
### Second  
### mArray = newArray([3,4,6])    // 1- Populate array using number indexes
###
### Third 
### a=3  b=4  c=6                 // 1- Assign number to letter
### mArray = newArray([a,b,c])    // 2- Populate array using letter reference to indexes
###
###------------------------------------------------------------------------

Func newArray(dimArray)

     sizeList = len(dimArray)             // [3,4,6]    
     newParms = []
     
     for i = 2 to sizeList
        Add(newParms, dimArray[i])
     next

     aList = list(dimArray[1])

     if sizeList = 1
        return aList
     ok

     for t in aList
         t = newArray(newParms)           // ===>>> Recursive
     next

return aList

//===========================================
/* OUTPUT  [3,4,6]  3 Blocks, 4 Rows, 6 Cols

Populate
Print
1 2 3 4 5 6
7 8 9 10 11 12
13 14 15 16 17 18
19 20 21 22 23 24

25 26 27 28 29 30
31 32 33 34 35 36
37 38 39 40 41 42
43 44 45 46 47 48

49 50 51 52 53 54
55 56 57 58 59 60
61 62 63 64 65 66
67 68 69 70 71 72

*/
//============================================

