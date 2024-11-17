CLEAR

* Initialize the size
size = 1000000

* Create an array with the specified size
DIMENSION aList[size]

* Start the clock
t1 = SECONDS()

* Fill the array
FOR t = 1 TO size
    aList[t] = t
NEXT

* Stop the clock
t2 = SECONDS()

* Display the elapsed time
? t2 - t1
