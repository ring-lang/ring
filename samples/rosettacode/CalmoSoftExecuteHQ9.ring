# Project : Execute HQ9
# Date    : 2017/09/12
# Author  : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>

bottle("hq9+HqQ+Qq")
 
func bottle(code)
     accumulator = 0
     for i = 1 to len(code)
         switch code[i] 
                on "h"
                    see "Hello, world!" + nl
                on "H"
                    see "hello, world!" + nl
                on "q"
                    see code + nl
                on "Q"
                    see code + nl
                on "9"
                    bottles = 99
                    while bottles > 0
                          see "" + bottles + " bottles of beer on the wall, " 
                          see "" + bottles + " bottles of beer," + nl
                          bottles = bottles - 1
                          see "take one down, pass it around, "
                          see "" + bottles + " bottles of beer on the wall." + nl
                    end
                on "+"
                    accumulator = accumulator + 1
         off
     next
