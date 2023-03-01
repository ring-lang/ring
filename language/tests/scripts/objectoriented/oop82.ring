aList = -1:-10
? aList

? sort(aList)

mypoint = new point {x=10 y=20 z=30}

try
	? sort(mypoint)
catch
	? "We can't sort an object!"
end

try
	? reverse(mypoint)
catch
	? "We can't reverse an object!"
end

try
	? insert(mypoint,:wow)
catch
	? "We can't insert to an object!"
end

try
	? add(mypoint,:wow)
catch
	? "We can't add to an object!"
end

try
	? swap(mypoint,1,2)
catch
	? "We can't use swap with an object!"
end

try
	? min(mypoint)
catch
	? "We can't use min() with an object!"
end

try
	? max(mypoint)
catch
	? "We can't use max() with an object!"
end

? mypoint

class point x y z