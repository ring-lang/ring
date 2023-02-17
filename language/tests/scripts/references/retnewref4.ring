# Author: Ilir Liburn
# Updated by Fayed to return list item instead of using ref()

x = test()
? "--------------"
? refcount(x)
? type(x)
? len(x)
? x
? "--------------"
for y in x
        ? type(y)
        ? y
        ? refcount(y)
        y = 0
next
? "--------------"
? x
? refcount(x)
? :done

func test
        a = [[ref(a),ref(a),3],[4,5,6]]
        ? a
        return a[1]
