Func Main
        aList = [1,2,3,4,5]
        aList2 = square(aList)
        see "aList" + nl
        see aList
        see "aList2" + nl
        see aList2

Func Square aPara
        a1 = aPara              # copy the list
        for x in a1
                x *= x
        next
        return a1               # return new list
