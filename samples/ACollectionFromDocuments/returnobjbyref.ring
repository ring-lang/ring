o1 = new Container
myobj = o1.addobj()     # the assignment will create another copy
myobj.x = 100
myobj.y = 200
myobj.z = 300
see o1.aobjs[1]         # print the object inside the container
see myobj               # print the copy

Class Container
        aObjs = []
        func addobj
                aobjs + new point
                return aobjs[len(aobjs)]        # return object by reference

Class point
        x  = 10
        y  = 20
        z  = 30
