New App { multiplication_table(12) }
Class App 
	func multiplication_table n
  		nSize = 4   See "    |   " 
  		for t = 1 to n see  fsize(t, nSize) next 
  		see nl + "----+-" + copy("-", nSize*n) + nl
  		for t1 = 1 to n
     		see fsize(t1, nSize) + "|   "
     		for t2 = 1 to n 
     			if t2 >= t1 
     				see  fsize(t1*t2,nSize) 
     			else 
     				see copy(" ", nSize) 
     			ok 
     		next
     		see nl
  		next 
	func fsize x,n return string(x) + copy(" ",n-len(string(x)))
