Func Main
        see "before test2()" + nl
        f = Test2(:Test)
        see "after test2()" + nl
        call f()

Func Test
        see "Message from test!" + nl

Func Test2 f1
        call f1()
        See "Message from test2!" + nl
        return f1
