# Author: Ilir Liburn
# Updated by Fayed

# Using Ref() with the range operator or list() 
# function doesn't create a new reference because these temp. lists
# doesn't have a variable that contains it.
# Also, using Ref() with (new object) or ([1,2,3]) 
# doesn't create a reference because Ring will ignore the temp. variable
# This is more natural (works as expected) - Thanks to Ilir 
# Using Ref() with (new object then braces { }) will keep the temp. variable
# This will lead to Ref() creating a reference until this temp. variable is deleted

? "**************"
x = ref(1:3)
? x
? refcount(x)
x2 = x
? refcount(x)
? "**************"
x = ref(list(3))
? x
? refcount(x)
x2 = x
? refcount(x)
? "**************"
y = ref(new RefIt { data="test" })
? y
? refcount(y)
y2 = y
? refcount(y)
? "**************"
z = ref([1,2,3])
? z
? refcount(z)
z2 = z
? refcount(z)

class RefIt
        data