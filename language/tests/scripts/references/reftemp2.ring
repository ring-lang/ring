o1 = new obj 
? refcount(o1)

o2 = new obj { }
? refcount(o2)

o3 = ref(new obj)
? refcount(o3)

o4 = ref(new obj) {}
? refcount(o4)

o5 = ref(new obj {})
? refcount(o5)

o6 = new obj
o6 = ref(o6)
? refcount(o6)

class obj