Func Main
        aList = [1,2,3,4]
        Map (aList , func x {
                                return x*x
                            } )
        see aList
        aList = [4,9,14,25]
        Map(aList, :myfilter )
        see aList
        aList = [11,12,13,14]
        Map (aList , func x {
                if x%2=0
                        return "even"
                else
                        return "odd"
                ok
        })
        see aList

Func myfilter x
        if x = 9
                return "True"
        else
                return "False"
        ok

Func Map aList,cFunc
        for x in aList
                x = call cFunc(x)
        next
