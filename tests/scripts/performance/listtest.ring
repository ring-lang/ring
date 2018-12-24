nLen = 4000	aArray = []	nStart = clock()
for nI = 1 to nLen
    aDetail = [] for nJ = 1 to nLen  aDetail + (nJ * nI) next
    aArray + aDetail 
next
nTime = (clock()-nStart)/clockspersecond() ? nTime
? "Filling the bidimensional test array with " +  nLen  +
  " elements each took " + nTime + " seconds"

