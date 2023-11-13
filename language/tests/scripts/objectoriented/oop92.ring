new data {
	for m=1 to 3
		? "Before using aList"
		aList[x][y] = [x,x+y,x*y]
		? "Counter: " + counter
		? "After using aList"
		if ! ismethod(self, :getx) addmethod(self, :getx, func { ? :x_getter counter++ return x }) ok
		if m=2 addmethod(self, :getalist, func { ? :alist_getter counter+=10 return aList }) ok
	next
}

class data
 
	width = 100   height = 100
	aList = list(width,height)

	x=1 y=1 counter=0
	