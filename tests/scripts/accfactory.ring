# AccumulatorFactory

oGenerator = new Generator

Func main
	oGenerator {
		accumulator = generator(1)
		see call accumulator(5)
		see nl
		generator(3)
		see call accumulator(2.3)
	}

Class Generator
	n = 0
	func generator i
		n += i
		return func d {
			oGenerator {
				n += d
				return n
			}
		}
