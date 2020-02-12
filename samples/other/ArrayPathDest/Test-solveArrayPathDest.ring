// Test routine for CALLing pathSrcDest(aSquare, x,y,s,t)
// Provide an Array, srcX,srcY, destX,destY
// ARRAY:  0=Empty  1= Occupied
// FIND:   Empty to Empty
//
// CALL:   pathSrcDest(aSquare, x,y,s,t)
// RETURN: True / False


load "stdlib.ring"
load "solveArrayPathDest.ring"

//--------------------------------------------------
//           1 2 3 4 5 6 7 8 9 0
aSquare  = [[0,1,0,0,1,0,0,0,0,1],  // 1    0 ... 11
            [0,0,0,0,1,1,1,1,1,0],  // 2   10 ... 21
            [0,1,0,0,1,1,1,1,1,1],  // 3
            [0,0,0,1,0,0,0,1,0,0],  // 4
            [0,1,0,1,0,0,0,0,1,0],  // 5
            [1,0,0,1,1,0,0,0,0,0],  // 6
            [0,0,0,0,0,0,0,1,0,0],  // 7
            [1,0,1,0,1,0,0,1,1,0],  // 8
            [0,0,0,0,0,1,1,0,0,0],  // 9
            [0,1,0,0,1,0,0,1,0,1]]  // 0        
 
//------------------------------------------------------------------------
// Path 6-5 to 2-10 ng , 6-5 to 1-4 ok , 6-5 to 10-6 ng ,  6-5 to 10-1 ok

pathTF = pathSrcDest(aSquare, 6,5,2,10)
            See "PathTF: 6,5,2,10: "+pathTF +nl

pathTF = pathSrcDest(aSquare, 6,5,1,4)
            See "PathTF: 6,5,1,4: "+pathTF +nl

pathTF = pathSrcDest(aSquare, 6,5,10,6)
            See "PathTF: 6,5,10,6: "+pathTF +nl

pathTF = pathSrcDest(aSquare, 6,5,10,1)
            See "PathTF: 6,5,10,1: "+pathTF +nl
            
See nl+"pathSrcDest Done! "+nl          


