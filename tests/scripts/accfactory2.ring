oGenerator = New Generator(:oGenerator)

Func main
    oGenerator {
        accumulator = generator(1)
        see call accumulator(5)
        see nl
        generator(3)
        see call accumulator(2.3)
    }

Class Generator

    n = 0   cObj = "objname"

    func init x  cObj=x

    func generator i

        n += i        

	return eval(substr("return func d { 	
			#objname# { 
				n += d  
				return n  
			}
		}","#objname#",cObj)) 
 