# Author: Ilir Liburn

tmp = new Temp { data="test" }
lst = [ref(tmp)]
? lst
tmp = NULL
lst[1] { data="test2" }
? lst

class Temp
        data