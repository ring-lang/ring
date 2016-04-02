mergemethods("count","share")
mergemethods("count2","share")

o1 = new count  { test() }
o1 = new count2 { test() }

Class Share
        func one
                see "one" + nl
        func two
                see "two" + nl
        func three
                see "three" + nl

Class Display
        Func printline
                see copy("*",20) + nl

Class Count from Display
        Func test
                printline()
                one()
                two()
                three()
                printline()

Class Count2 from Display
        Func test
                three()
                two()
                one()
                printline()
