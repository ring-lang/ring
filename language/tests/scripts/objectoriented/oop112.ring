# Test creating an object using the Temp. Memory
# Then using a loop that free Temp. lists (Doesn't touch the Object defined before it)

v = 0

new point {

	for m=1 to 10000
		mylist = 1:10
		v = mylist[10]
		v = x
	next

}

? v


class point 
	x=10 y=20 z=30