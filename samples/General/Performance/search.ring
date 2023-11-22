? "Create list contains 100,000 items"
aList = 1:100000

? "Do 3000 search operation - Find the last item (Worst Case!)"
c = clock()

for t = 1 to 3000
        find(alist,100000)
next

? "Time: " + ( clock() - c ) / clockspersecond() + " seconds"
