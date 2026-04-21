see "using loop from 1 to 10000000 "
t1 = clock()
for x = 1 to 10000000 next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

see "using 10000000 variable read "
t1 = clock()
for x = 1 to 10000000 t1 next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

see "using 10000000 variable write "
t1 = clock()
for x = 1 to 10000000 t=1000 next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

see "using 10000000 list item read "
aList = 1:10
t1 = clock() 
for x = 1 to 10000000 aList[1] next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

see "using 10000000 list item write "
t1 = clock() 
for x = 1 to 10000000 aList[1] = 1 next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"


see "calling 10000000 C functions "
t1 = clock()
for x = 1 to 10000000 nothing() next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

see "calling 10000000 Ring functions "
t1 = clock()
for x = 1 to 10000000 test() next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

o1 = new test

see "calling 10000000 Ring methods using the dot operator "
t1 = clock()
for x = 1 to 10000000 o1.test() next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

see "calling 10000000 Ring methods using braces (outside the loop) "
t1 = clock()
o1 { for x = 1 to 10000000 test() next }
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

see "using 10000000 object brace open/close "
t1 = clock()
for x = 1 to 10000000 o1 { } next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

see "calling 10000000 Ring methods using braces (inside the loop) "
t1 = clock()
for x = 1 to 10000000 o1 { test() } next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

func test return 0

class test
        func test return 0