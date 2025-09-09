var = "test"

try
	var -= [1,2,3]
catch
	? "Pass error"
done

? var

var = 10

try
	var -= [1,2,3]
catch
	? "Pass error"
done

? var

var = [5]

try
	var -= [1,2,3]
catch
	? "Pass error"
done

? var

var = new point { x=100 y=200 z=300 }

try
	var -= [1,2,3]
catch
	? "Pass error"
done

? var

class point x y z