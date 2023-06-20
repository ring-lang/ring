# Author: Ilir Liburn
# Updated by Fayed

? "Start the test!"

? test2(test(),test(),test())
? copy("*",10)

? test() + test() + test()

? ""
? "End of test!"

func test
        return ref([0])

func test2 a,b,c
        ? refcount(a)
        ? refcount(b)
        ? refcount(c)
        x = a
        y = b
        z = c
        ? copy("*",30)
        ? refcount(x)
        ? refcount(y)
        ? refcount(z)
        ? copy("*",30)
        return ref(a+b+c+[3])