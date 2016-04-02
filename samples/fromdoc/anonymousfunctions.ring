test( func x,y {
                        see "hello" + nl
                        see "Sum : " + (x+y) + nl
               } )

new great { f1() }

times(3, func { see "hello world" + nl } )

func test x
        call x(3,3)
        see "wow!" + nl

func times n,x
        for t=1 to n
                call x()
        next

Class great
        func f1
                f2( func { see "Message from f1" + nl } )

        func f2 x
                call x()
