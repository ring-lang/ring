/*
          Application : Clock
          Author      : Mahmoud Kibreet
          Date        : 2018.01.28
*/

t1 = clock()

for x = 1 to 1000000
next

? (clock() - t1)/clockspersecond()
