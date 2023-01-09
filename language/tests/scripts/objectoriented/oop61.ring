x = new Temp 
x { y=10 ? self }
x = 0 
Try
	x { y=10 }
catch
	? "x is not an object!"
done

class Temp
	y