# Project: Matrix Multiplication
# Date   : 2018/07/08
# Author : Gal Zsolt (~ CalmoSoft ~), Bert Mariani
# Email  : <calmosoft@gmail.com>
#
# NASA 3 Problem: MatrixMultiple

load "stdlib.ring"
nr = [500, 1000, 1500]

for n = 1 to len(nr)
    ind = nr[n]

    ###-------------------------------
    ### Create Arrays

    starttime = clock()
        A = createDimList([ind,ind])
        B = createDimList([ind,ind])
        C = createDimList([ind,ind])

    endtime  = clock()
    difftime = endtime - starttime
    see nl +"Create.. Arrays A,B,C: Len = "+ ind +" Time-msec: "+ difftime + nl        

    
    ###-----------------------------
    ### Populate Arrays A, B: 
    
    starttime = clock()
        Counter = 1
        for x = 1 to ind
            for y = 1 to ind
                A[x][y] = Counter   ### random(ind)
                B[x][y] = Counter   ### random(ind)
                Counter++
            next
        next

    endtime  = clock()
    difftime = endtime - starttime
    see "Populate Arrays A,B..: Len = "+ ind +" Time-msec: "+ difftime + nl

            ###-------------------------------------------------
            ### Before: Print the array elements in block format

            /*
                for Col=1 to ind
                  for Row=1 to ind
                            See " A: "+ A[Col][Row] See " "
                            See " B: "+ B[Col][Row] See " "
                  next
                    See nl
                next
            */  
            ###-------------------------------------------------
    
    ###-----------------------------    
    ### Multiple Arrays A x B => C
    
    starttime  = clock()
        for i = 1 to ind
            for j = 1 to ind
                result  = A[i][j] * B[i][j]
                C[i][j] = result
            next
        next
         
    endtime  = clock()
    difftime = endtime - starttime
    see "Multiply Arrays AxB=C: Len = "+ ind +" Time-msec: "+ difftime + nl
    
    ###--------------------------

            ###-------------------------------------------------
            ### After: Print the array elements in block format

            /*
                for Col=1 to ind
                  for Row=1 to ind
                            See " C: "+ C[Col][Row] See " "
                  next
                    See nl
                next
            */
            ###-------------------------------------------------
            
next

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
