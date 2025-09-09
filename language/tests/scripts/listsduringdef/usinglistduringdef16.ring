var = "test"
try 
	var += new point 
catch 
	? "Pass error"
done 

? var 

var = 2025

try 
	var += new point 
catch 
	? "Pass error"
done 

? var 

var = 1:3

try 
	var += new point 
catch 
	? "Pass error"
done 

? var 

var = new point { x = 100 y = 200 z = 300}

try 
	var += new point 
catch 
	? "Pass error"
done 

? var 


class point x y z 

	