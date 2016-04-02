o1 = new test
aList = methods(o1)

for x in aList
        cCode = "o1."+x+"()"
        eval(cCode)
next

Class Test
        func f1
                see "hello from f1" + nl
        func f2
                see "hello from f2" + nl
        func f3
                see "hello from f3" + nl
        func f4
                see "hello from f4" + nl
