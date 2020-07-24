o1 = new Test

see isprivatemethod(o1,"f1") + nl +
    isprivatemethod(o1,"f2")

Class Test
        func  f1
                see "message from f1()" + nl
        private
                func f2
                        see "message from f2()" + nl
