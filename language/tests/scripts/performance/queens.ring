n = 9
x = 1:n
t1 = clock()
nQueen(1,n) 
? "Total Seconds : " + ( (clock() - t1) / ClocksPerSecond() )

func Place k,i
	for j=1 to k-1 
		if( x[j] = i   OR                  	
			fabs(x[j]-i) = fabs(j-k) )     
			return 0
		ok
	next
	return 1

func nQueen k, n
	 for i=1 to n 
		  if place(k,i)
		  	   x[k] = i			   
			   if ! (k=n)
				nQueen(k+1,n)
			   ok
		  ok
	 next