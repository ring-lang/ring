# Pass parameter to a setter method 
# Then try to access the private attribute 

o = new point 
o.test(10)
? o.test2()

try
	? o.x
catch
	? "good"
done


class point 

	func test t
		x=t

	func test2
		return x

	private
		x=10 y=20