num = 12.203456

nod = DecimalsCount(num) 
? "number of decimals = " + nod 

func DecimalsCount(num)
	nr  = 1
	dec = 0
	while true 
		nr = nr * 10
		dec++
		newNum = num*nr - ceil(num*nr)
		if newNum = 0
			return dec 
			exit
		ok
	end