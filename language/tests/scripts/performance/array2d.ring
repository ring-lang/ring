nLen   = 4000    
nStart = clock()
aArray = list(nLen,nLen)
nTime = (clock() - nStart)/clockspersecond() 
? "Creating the bidimensional test array (4000x4000 = 16 Million items) took " + nTime + " seconds"
nStart = clock()
for nI = 1 to nLen
    for nJ = 1 to nLen
        aArray[nI][nJ] = nJ * nI
    next
next
nTime = (clock() - nStart)/clockspersecond() 
? "Filling the bidimensional test array took " + nTime + " seconds"
