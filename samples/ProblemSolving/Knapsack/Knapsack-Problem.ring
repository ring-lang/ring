// Knapsack Problem
// Bert Mariani  2020-10-07
//
// https://gtucse.blogspot.com/2012/12/01-knapsack-problem-using-dynamic.html
//
// We are given n items with some weights and corresponding values and a knapsack of capacity W. 
// The items should be placed in the knapsack in such a way that 
// the total value is maximum and total weight should be less than knapsack capacity.
//

//----------------------------------------
// AUTOMATIC

Weight = [0,1,2, 5, 6, 7]  // [MAX]
Value  = [0,1,6,18,22,28]  // [MAX]
KCap   = 11 +1             // Capacity +1
Nbr    = 5  +1             // Objects  +1
V      = list(KCap,KCap)
###     Value = 40

 
# Weight = [0, 10,  20,  30]  // [MAX]
# Value  = [0, 60, 100, 120]  // [MAX]
# KCap   = 50 +1              // Capacity +1
# Nbr    = 3  +1              // Objects  +1
# V      = list(KCap,KCap)  
###      Value = 220

//==============================

Func main()

   See "Knapsack: create Manual or Auto: Enter M or A: "
   Give Letter
   Letter = Upper(Letter)
   if Letter = 'M'  Manual = 'M'  else    Manual = 'A'  ok
   
   //----------------
   
   if Manual = 'M'
   
       See nl+"Enter number of Objects you want: "
          Give Nbr   Nbr = number(Nbr)
       
       See nl+"Enter Weight and Values in ascending order of vales: "
          for i=1 to Nbr
          
            See nl+"Enter Weight and Value for Object "+i +" : "
            Give Wgt    Wgt = number(Wgt)
            Weight[i+1] = Wgt
            
            Give Val    Val = number(Val)
            Value[i+1]  = Val
            
           next
       
       See nl+"Enter Knapsack Capacity: "
          Give Cap  Cap = number(Cap)
          KCap    = Cap +1                   // Weight and Value column-1 = 0
          NBR     = Nbr +1
 
   else
      // AUTOMATIC values are in global section
   ok
   
   //-------------------   

   knapsackDP(Nbr, KCap)

   backtracking()
 

return

//==============================

Func knapsackDP(Nbr, KCap)

 for i=1 to KCap                  // Knapsack Capacity
   V[1][i] = 0                    // Row 1 = 0
 next

 for i=1 to Nbr 
   V[i][1] = 0                    // Col 1 = 0
 next

 for i=2 to Nbr 
  for j=2 to KCap
  
   if (j - Weight[i]) <=  0       // Ring-Index=1
      V[i][j] = V[i-1][j]   
   else
      V[i][j] = max( V[i-1][j], V[i-1][j-Weight[i]] + Value[i] )
   ok 
    
  next
 next
 
 //----------------------
 // Output matrix
  
   See nl+"Index:   "+ tab  
   for i=1 to KCap
      if i < 10
         See "   "+ i
      else
         See "  "+ i
      ok
   next 

 See nl+"-----------------------------------------------------------------------------"

 for i=1 to Nbr 
 
   See nl+" W"+i +"="+Weight[i] +" V"+i +"="+ Value[i] + tab   // ,i,Weight[i],i,Value[i]);
  
   for j = 1 to KCap
      if V[i][j]< 10
         See "   "+ V[i][j] 
      else
         See "  "+ V[i][j]
      ok
   next

 next
 
 See nl+"-----------------------------------------------------------------------------"
 See nl+" Maximum Value carry by knapsack is: "+ V[Nbr][KCap]
 See nl+"-----------------------------------------------------------------------------"

return

//==============================

Func max(a,b)
  if a >= b   
      return a
  ok
return b


//==============================

Func backtracking()

 j1 = KCap                  // Knapsack Capacity
 
 See nl+"Included Object  Weight  Value"+nl
 
 for i=Nbr to 2  step -1

   if j1-Weight[i] >= 1
     
     if ( V[i][j1] != V[i-1][j1] )  &&  ( V[i][j1] = V[i-1][j1-Weight[i]] + Value[i] )
     
      See "  i-Vert: "+i  +" Weight:  "+ Weight[i]  +" Value:  "+ Value[i] +nl  // Answer
      
      j1 = j1-Weight[i]
      
     ok
   ok
 next


return



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

   sizeH = len(array)
   sizeW = len(array[1])
   
   for i = 1 to sizeH
      See "...: "+i +" > "
      for j = 1 to sizeW
         See " "+ array[i][j]
      next
      See nl
      
   next
   See nl+nl

return

//-----------------------------
//==============================


/*
OUTPUT
 
Enter number of Object you want: 5
 Enter Weight and Values in ascending order of Values
 Enter Weight and Value for Object 1: 1 1
 Enter Weight and Value for Object 2: 2 6
 Enter Weight and Value for Object 3: 5 18
 Enter Weight and Value for Object 4: 6 22
 Enter Weight and Value for Object 5: 7 28
Enter knapsack Capacity: 11

                0   1   2   3   4    5    6    7    8    9   10  11
--------------------------------------------------------------------------
 w0= 0 v0= 0  | 0   0   0   0   0    0    0    0   0    0    0    0
 w1= 1 v1= 1  | 0   1   1   1   1    1    1    1   1    1    1    1
 w2= 2 v2= 6  | 0   1   6   7   7    7    7    7   7    7    7    7
 w3= 5 v3=18  | 0   1   6   7   7   18   19   24  25   25   25   25
 w4= 6 v4=22  | 0   1   6   7   7   18   22   24  28   29   29   40
 w5= 7 v5=28  | 0   1   6   7   7   18   22   28  29   34   35   40
--------------------------------------------------------------------------
 Maximum Value carry by knapsack is:40
--------------------------------------------------------------------------
Included Object          Weight          Value
--------------------------------------------------------------------------
 5                           6              22
 4                           5              18
 
 */
