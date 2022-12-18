/*
**	Knuth's conjecture
*/

# Example: Reach to number 5 from number 4 using Fact, Sqrt & Floor

/*
**	---[Output]---
**
**	=======================================================
**	Input: 4
**	=======================================================
**	Fact(4): 24
**	Fact(Fact(4)): 620448401733239409999872.00
**	Sqrt(620448401733239409999872.00): 787685471322.94
**	Sqrt(787685471322.94): 887516.46
**	Sqrt(887516.46): 942.08
**	Sqrt(942.08): 30.69
**	Sqrt(30.69): 5.54
**	=======================================================
**	Output: floor(5.54): 5
**	=======================================================
**
*/

func main
	line()
	nInput = 4
	? "Input: " + nInput
	line()
	v = fact(nInput)
	? "Fact("+nInput+"): " + v
	r = fact(v)
	? "Fact(Fact("+nInput+")): " + r
	for t=1 to 5
		see "Sqrt("+r+"): "
		r = sqrt(r)
		? r
	next
	line()
	nOutput = floor(r)
	? "Output: floor(" + r + "): " + nOutput
	line()

func fact n
	out = 1
	for t=n to 1 step -1
		out *= t
	next
	return out

func line
	? Copy("=",55)