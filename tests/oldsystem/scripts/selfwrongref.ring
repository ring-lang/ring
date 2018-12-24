# Same class instances(including subclass)
instanceA = new A
instanceB = new B
instanceC = new A

instanceB.attr = 1
instanceC.attr = [2] # Only when last instance's attribute is re-assigned to list type
printAttr()

instanceA.assignWithoutSelf('A') # (This works fine)
printAttr()

instanceA.assignWithSelf('A') # Only when 'self' is used to assignment
printAttr() # assignment with 'self' to any instance is conducted to the last instance of the class

# after first assignment with 'self', everything is fine.
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