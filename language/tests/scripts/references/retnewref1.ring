# Author: Ilir Liburn

oid = NULL

func main
        x = test()
        ? objectid(x) = oid
        ? refcount(x)
        ? x
        ? :done

func test
        a = [ref(a),ref(a),3]
        oid = objectid(a)
        return ref(a)