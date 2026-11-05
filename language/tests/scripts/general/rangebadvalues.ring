? "Start"

? 1:5
? "a":"e"

try
	? "1":"11"
catch
	? "Pass Error"
done

try
	? "1":2
catch
	? "Pass Error"
done

try
	? 1:"2"
catch
	? "Pass Error"
done

try
	? [1]:[1]
catch
	? "Pass Error"
done

oPoint = new Point

try
	? 1:o
catch
	? "Pass Error"
done

try
	? "a":o
catch
	? "Pass Error"
done

try
	? [1]:o
catch
	? "Pass Error"
done

? "Done"

class point x y z
