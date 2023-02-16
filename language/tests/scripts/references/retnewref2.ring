oid = NULL

func main
        x = test()
        ? objectid(x) = oid
        ? refcount(x)
        ? x
        ? :done

func test
        a = [10]
	b = ref(a)
        oid = objectid(a)
        return ref(a)