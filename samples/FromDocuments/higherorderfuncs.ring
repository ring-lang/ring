Func Main
        times(5,:test)

Func Test
        see "Message from the test function!" + nl

Func Times nCount,F

        for x = 1 to nCount
                Call F()
        next
