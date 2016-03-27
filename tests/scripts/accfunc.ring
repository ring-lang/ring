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

    aN = []   

    func generator i

	aN + i
        return eval(substr("return func d {                           
           oGenerator {
               aN[#id#] += d
               return aN[#id#]
           }

       }","#id#",string(len(aN))))