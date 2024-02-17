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

load "stdlibcore.ring"

mySquare = [[]]
Rows = 1
Cols = 1
srcX = 1
srcY = 1
dstX = 1
dstY = 1

//----------------------------------------------------     
// Sample 2D Array      
/*
//           1 2 3 4 5 6 7 8 9 0
mySquareX = [[0,1,0,0,1,0,0,0,0,1],  // 1    0 ... 11
            [0,0,0,0,1,1,1,1,1,0],  // 2   10 ... 21
            [0,1,0,0,1,1,1,1,1,1],  // 3
            [0,0,0,1,0,0,0,1,0,0],  // 4
            [0,1,0,1,0,0,0,0,1,0],  // 5
            [1,0,0,1,1,0,0,0,0,0],  // 6
            [0,0,0,0,0,0,0,1,0,0],  // 7
            [1,0,1,0,1,0,0,1,1,0],  // 8
            [0,0,0,0,0,1,1,0,0,0],  // 9
            [0,1,0,0,1,0,0,1,0,1]]  // 0        
 
*/
//---------------------------------------------------
// CALL  pathSrcDest(array, srcX, srcY, dstX, dstY)
// Return: True / False
//
// Path 6-5 to 2-10 ng , 6-5 to 1-4 ok , 6-5 to 10-6 ng ,  6-5 to 10-1 ok

Func pathSrcDest(aSquare,x,y,s,t)

    mySquare = aSquare         // Working Copy 
    
    //-------------------------------------
    // Fixable: Find size of 2D Array => Rows x Cols
    Rows = len(mySquare)       // Size: 10     Rows
    Cols = len(mySquare[1])    // Size[1]: 10  Row-1 Cols

    srcX = x  srcY = y
    dstX = s  dstY = t 
    
        //See "CALLED Square: "+nl
        //See "mySquare: Rows-Cols: "+ Rows +"-"+ Cols +" Src: "+ SrcX +"-"+ SrcY +" Dst: "+ DstX +"-"+ DstY  +nl
        //DisplaySquareVisit( )        // Called Square

    VisitSquare(srcX,srcY)
    pathTF = CheckResult()
        
    mySquare[srcX][srcY] = 'S'  // Insert Start
    mySquare[dstX][dstY] = 'G'  // Insert Goal
    
        //See "UPDATED Square: PathTF: " + pathTF + " Src:  "+ SrcX + "-" + SrcY + " Dst:  "+ DstX + "-" + DstY +nl
        //DisplaySquareVisit()             // SHOW  Updated mySquare with "v" visited results


  
     return pathTF                       // Return TRUE / FALSE 

  
//===============================

Func DisplaySquareVisit()
    See nl
    for i = 1 to Rows
        for j = 1 to Cols
            See " "+ mySquare[i][j]
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
       if mySquare[x-1][y] = 1 or mySquare[x-1][y] = 'v'          
       else 
         mySquare[x-1][y] = 'v'
         VisitSquare(x-1,y)
       ok
   ok
         
//SOUTH
   if (x+1) % Rows != 1 
       if mySquare[x+1][y] = 1 or mySquare[x+1][y] = 'v'            
       else 
         mySquare[x+1][y] = 'v'
         VisitSquare(x+1,y)
       ok
   ok
                
// EAST 
   if (y-1) > 0   
      if mySquare[x][y-1] = 1 or mySquare[x][y-1] = 'v'              
       else 
         mySquare[x][y-1] = 'v'              
         VisitSquare(x,y-1)
       ok  
   ok
         
   //WEST
   if (y+1) <= Cols 
       if mySquare[x][y+1] = 1 or mySquare[x][y+1] = 'v'           
       else 
         mySquare[x][y+1] = 'v'             
         VisitSquare(x,y+1)
       ok                
   ok 

   //See "Exit - VisitSquare: xy " +  x +"-"  +y +nl   // Show Recursive calls
                                
return  

//==========================================

Func CheckResult()
   
    if mySquare[dstX][dstY] = 'v'
        //See "CheckResult: Path Open.: " + srcX + "-" + srcY  + " To: "  + dstX +"-" + dstY + " Value: " + mySquare[dstX][dstY] + " TRUE" + nl
        return 1
    else
        //See "CheckResult: Path Block: " + srcX +"-" + srcY + " To: " + dstX +"-" + dstY + " Value: " + mySquare[dstX][dstY] + " FALSE" + nl
        return 0 
    ok

return 

//===========================================
