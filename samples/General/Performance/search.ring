nSize = 100_000
? "Create list contains "+nSize+" items"
aList = list(nSize)
aList[nSize] = nSize

? "Do 3000 search operations - Find the last item (Worst Case!)"
c = clock()

for t = 1 to 3000
        find(alist,100000)
next

? "Time: " + ( clock() - c ) / clockspersecond() + " seconds"
