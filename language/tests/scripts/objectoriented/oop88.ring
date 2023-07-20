# Return another object from init() method

myobj = new Obj() { ? classname(Self) }
? classname(myobj)

class Obj
   func init
      return new Obj2

class obj2

