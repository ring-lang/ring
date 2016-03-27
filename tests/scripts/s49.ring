
main()
sum(3,4)
sum( sum(1,2) , sum(3,4) )
loop()
list()
seef()
see NL
see "welcome" 
delay()
see "to" 
delay()
see "my" 
delay() 
see "new" 
delay()
see "language" 
delay()

see NL
see fact(4)
see NL
return

func main
	see "nice" + NL
	return

func sum x,y
	see "" + (x+y) + NL
	return x+y

func loop
	for x = 1 to 10
		see x
		see NL
		if x = 3
			see "number three " + NL
		ok
	next
	return

func list
	list = ["mahmoud","samir","fayed"]
	for x = 1 to 3
		see list[x] + NL
		if x = 2 
			return
		ok
	next
	return

func seef
	see "wow i am here"
	return

func delay
	for t = 1 to 1000000
	next
	see NL
	return	

func fact x
	#see " x value is " + x + NL
	if x > 1
		return x * fact(x-1)
	else
			return 1
	ok
