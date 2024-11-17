t1 = clock()
? Fibonacci(500)
t2 = clock()
? t2-t1

Func Fibonacci n
	if n = 0 return 0 ok
	if n = 1 return 1 ok 
	aFibRes = [ ["0", 0], ["1", 1] ]
	if n > 1
		for t=2 to n
			aFibRes[""+t] = aFibRes[""+(t-1)] + aFibRes[""+(t-2)]
		next 
		return aFibRes[""+n]
	ok