# Author: Ilir Liburn

? rec(0)

func rec x

        if x = 900
                y = [ref(y),ref(y)]
                return y
        ok

        return rec(x++)