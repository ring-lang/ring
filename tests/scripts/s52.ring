see "hello world"
see NL + sum(5,5) + NL
good()
test()
loop()

see novalue()

if novalue() = NULL
	see "function return null" + NL
else
	see "function return value" + NL
ok

genvar = 1

see fact2(1000)
see NL
see " General variable value : " + genvar + NL
see fact(2000)
see NL

func test
	see "nice" + NL

func good
	see "good" + NL

func loop
	for x = 1 to 10
		see x 
		see NL
	next

func sum x,y
	return x+y

func novalue
	see "no value " + NL

func fact x
	if x > 1
		return x + fact(x-1)
	else
			return 1
	ok

func fact2 x
	genvar = genvar + 1
	if x > 1
		return fact2(x-1)
	else
			return 
	ok