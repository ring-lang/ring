# Author: Ilir Liburn

a = [ref(a),2,3]
test(a[1])
? :done

func test(x)
        ? x
        a = NULL
        ? x
        ? type(x)
        ? refcount(x)
