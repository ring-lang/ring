# Author: Ilir Liburn
# Updated by Fayed

myobj = new Obj()

? myobj
? myobj.data
? myobj.data[3][2]

class Obj data
        func init
                this.data = [6,8,ref(this.data)]