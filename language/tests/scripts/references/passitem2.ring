# Author: Ilir Liburn

a = [ref(a),2,3]
a = test(a[1])
? "-----------"
? a
? :done

func test(x)
        ? x
        a = NULL
        ? x
        ? type(x)
        ? refcount(x)
        return x