/*
	Knuth's conjecture
*/

# Example: Reach to number 5 from number 4 using Fact, Sqrt & Floor

func main
	line()
	nInput = 4
	? "Input: " + 4
	line()
	v = fact(4)
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