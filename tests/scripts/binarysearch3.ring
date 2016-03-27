see "Creating the list..." + nl
t1 = clock()
aList = []
for x = 1 to 1000000
	aList + ("test"+x)
next
t2  = clock()
see "Time : " + (t2-t1) + "ms" + " clock 1 : " + T1 + " clock 2 : " + T2 + nl
/*
see "Sorting the list..." + nl
t1 = clock()
aList = sort(aList)
see "Time : " + (clock()-t1) + "ms" + nl
*/

see "Search..." + nl

t1 = clock()
see 'Find(aList,"test999999") : ' + Find(aList,"test999999") + nl
t2  = clock()
see "Time : " + (t2-t1) + "ms" + " clock 1 : " + T1 + " clock 2 : " + T2 + nl

t1 = clock()
see 'Find(aList,"test999999") : ' + Find(aList,"test999999") + nl
t2  = clock()
see "Time : " + (t2-t1) + "ms" + " clock 1 : " + T1 + " clock 2 : " + T2 + nl

t1 = clock()
see 'Find(aList,"test999999") : ' + Find(aList,"test999999") + nl
t2  = clock()
see "Time : " + (t2-t1) + "ms" + " clock 1 : " + T1 + " clock 2 : " + T2 + nl

t1 = clock()
see 'BinarySearch(aList,"test999999") : ' + BinarySearch(aList,"test999999") + nl
t2  = clock()
see "Time : " + (t2-t1) + "ms" + " clock 1 : " + T1 + " clock 2 : " + T2 + nl

t1 = clock()
see 'BinarySearch(aList,"test999999") : ' + BinarySearch(aList,"test999999") + nl
t2  = clock()
see "Time : " + (t2-t1) + "ms" + " clock 1 : " + T1 + " clock 2 : " + T2 + nl

t1 = clock()
see 'BinarySearch(aList,"test999999") : ' + BinarySearch(aList,"test999999") + nl
t2  = clock()
see "Time : " + (t2-t1) + "ms" + " clock 1 : " + T1 + " clock 2 : " + T2 + nl

t1 = clock()
see 'BinarySearch(aList,"test999999") : ' + BinarySearch(aList,"test999999") + nl
t2  = clock()
see "Time : " + (t2-t1) + "ms" + " clock 1 : " + T1 + " clock 2 : " + T2 + nl