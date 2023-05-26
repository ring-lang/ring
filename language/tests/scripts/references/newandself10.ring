# Author: Ilir Liburn
# Updated by Fayed

objpool = []

x = ref(new Obj { objpool[objectid(self)] = ref(self) })

? refcount(x)
? refcount(objpool[1][2])

class Obj