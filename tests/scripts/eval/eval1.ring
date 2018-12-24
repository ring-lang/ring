func main
	o1 = new point 
	see o1
	cTemp = test(o1)
	see cTemp

func test o1
	r = 'nice'
	cCode = "r = 'wow'"
	o1 {
		eval(cCode)
	}
	return r

class point 