// Name:   solveArrayPathDest
// Author: Bert Mariani
// Date:   2020-02-12
//
// Provide an Array, srcX,srcY, destX,destY
// ARRAY:  0=Empty  1= Occupied
// FIND:   Empty to Empty
//
// CALL:   pathSrcDest(aSquare, x,y,s,t)
// RETURN: True / False
//-----------------------------------------

load "stdlib.ring"

aSquare = [[]]
Rows = 1
Cols = 1
srcX = 1
srcY = 1
dstX = 1
dstY = 1

//----------------------------------------------------     
// Sample 2D Array      

//           1 2 3 4 5 6 7 8 9 0
aSquareX = [[0,1,0,0,1,0,0,0,0,1],  // 1    0 ... 11
            [0,0,0,0,1,1,1,1,1,0],  // 2   10 ... 21
            [0,1,0,0,1,1,1,1,1,1],  // 3
            [0,0,0,1,0,0,0,1,0,0],  // 4
            [0,1,0,1,0,0,0,0,1,0],  // 5
            [1,0,0,1,1,0,0,0,0,0],  // 6
            [0,0,0,0,0,0,0,1,0,0],  // 7
            [1,0,1,0,1,0,0,1,1,0],  // 8
            [0,0,0,0,0,1,1,0,0,0],  // 9
            [0,1,0,0,1,0,0,1,0,1]]  // 0        
 

//---------------------------------------------------
// CALL  pathSrcDest(array, srcX, srcY, dstX, dstY)
// Return: True / False
//
// Path 6-5 to 2-10 ng , 6-5 to 1-4 ok , 6-5 to 10-6 ng ,  6-5 to 10-1 ok

Func pathSrcDest(aSquare, x,y,s,t)

    //-------------------------------------
    // Find size of 2D Array => Rows x Cols
    Rows = len(aSquare)       // Size: 10     Rows
    Cols = len(aSquare[1])    // Size[1]: 10  Row-1 Cols

    srcX = x  srcY = y
    dstX = s  dstY = t 

    VisitSquare(srcX,srcY)
    //DisplaySquare()          // SHOW  aSquare with "v" visited results

    pathTF = CheckResult()
  
return pathTF

  
//===============================

Func DisplaySquare()
    See nl
    for i = 1 to Rows
        for j = 1 to Cols
            See " "+ aSquare[i][j]
        next
        See nl
    next
return

//===============================
// Visit N,S,E,W  
// Value: 1 = Occupied, 0 = Empty 'V' = Visited  
//  NorthLine -10  =>     <  1
//  SouthLine +10  =>     > 81   
//  EastSide   +1  Mod =>    1
//  WestSide   -1  Mod =>    0

Func VisitSquare(x,y)

// NORTH
   if (x-1) % Rows != 0   
       if aSquare[x-1][y] = 1  || aSquare[x-1][y] = 'v'     
          
       else 
         aSquare[x-1][y] = 'v'
         VisitSquare(x-1,y)
       ok
   ok
         
//SOUTH
   if (x+1) % Rows != 1 
       if aSquare[x+1][y] = 1  || aSquare[x+1][y] = 'v'  
            
       else 
         aSquare[x+1][y] = 'v'
         VisitSquare(x+1,y)
       ok
   ok
                
// EAST 
   if (y-1) > 0   
      if aSquare[x][y-1] = 1   || aSquare[x][y-1] = 'v'       
              
       else 
         aSquare[x][y-1] = 'v'              
         VisitSquare(x,y-1)
       ok  
   ok
         
   //WEST
   if (y+1) <= Cols 
       if aSquare[x][y+1] = 1   || aSquare[x][y+1] = 'v'     
           
       else 
         aSquare[x][y+1] = 'v'             
         VisitSquare(x,y+1)
       ok                
   ok 

   //See "Exit - VisitSquare: xy "+x+"-"+y +nl   // Show Recursive calls
                                
return  

//==========================================

Func CheckResult()
   
    if aSquare[dstX][dstY] = 'v'
        //See "CheckResult: Path Open.: "+ srcX +"-"+ srcY  +" To: "+ dstX +"-"+ dstY +" Value: "+ aSquare[dstX][dstY] +" TRUE" +nl
        return TRUE
    else
        //See "CheckResult: Path Block: "+ srcX +"-"+ srcY  +" To: "+ dstX +"-"+ dstY +" Value: "+ aSquare[dstX][dstY] +" FALSE" +nl
        return FALSE
    ok

return 

//===========================================






