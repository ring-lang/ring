//DotProduct p282

Load "stdlibcore.ring"
Load "MatrixLib.ring"
    
U = [[1],[ 2],[-1]]
V = [[3],[-2],[ 4]]
	
	vertU = len(U)   horzU = len(U[1])
    
    if (horzU != 1 AND horzV != 1) AND  (vertU != vertV) 
        See "Error: Dot Product Dimension: "+ nl
        See "horzU: "+ horzU +" horzV: "+ horzV +" MUST BE = 1 "+ nl
        See "vertU: "+ vertU +" vertV: "+ vertV +" MUST BE EQUAL " +nl
        return 1
    ok 


    Sum = 0
    for i = 1 to vertU
        product  = U[i][1] * V[i][1]
        Sum += product
    next

    Distance = Sum

See "DotProduct Sum: "+ Sum +nl

Nbr = DotProduct(U,V)
See "DotProduct Distance: "+Nbr +nl   
