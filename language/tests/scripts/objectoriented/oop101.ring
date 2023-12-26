# Author: Ilir Liburn

pn = new Parent { hello() }
pn = new Child()
? type(pn)
pn { hello() }

class Parent
        func init
                return this
        func operator cOp,cVal
                ? cOp
                return self
        func hello
                ? "Hello from Parent"

class Child from Parent
        func init
                return super.init()
        func hello
                ? "Hello from Child"

class SubChild from Child
        func init
                return super.init()
        func hello
                ? "Hello from SubChild"