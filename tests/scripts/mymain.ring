Func main
x = 10
myfunc()
See "X value = " + X  # here i expect that x will be (10)
                      # but i will get another value (6) because myfunc() uses x !
Func myfunc
   for x = 1 to 5
       See x + nl
   next