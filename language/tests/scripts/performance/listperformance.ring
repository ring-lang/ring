? "Create list contains 100,000 items"
aList = 1:100000

? "Do 1000 search operation - Find the last item (Worst Case!)"
c = clock() 

for t = 1 to 1000
	find(alist,100000)
next

? "Time: " + ( clock() - c ) / clockspersecond() + " seconds"
