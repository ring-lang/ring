o1 = new dynamicClass
see o1.var5 + nl        # output 5

Class DynamicClass
        for x = 1 to 10
                cStr = "var" + x + " = " + x
                eval(cStr)
        next
