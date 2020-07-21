# Same class instances(including subclass)
instanceA = new A
instanceB = new B
instanceC = new A

instanceB.attr = 1
instanceC.attr = [2] 
printAttr()

instanceA.assignWithoutSelf('A') 
printAttr()

instanceA.assignWithSelf('A') 
printAttr() 

instanceA.assignWithSelf('FineA')
instanceB.assignWithoutSelf('FineB')
printAttr()

func printAttr
        see "A: " see instanceA.attr see nl
        see "B: " see instanceB.attr see nl
        see "C: " see instanceC.attr see nl
        see nl

class A
        attr = 0

        func assignWithSelf value
                self.attr = value

        func assignWithoutSelf value
                attr = value

class B from A

class point x y z