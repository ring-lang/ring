p1 = new point {x=10 y=20 z=30}
k=0
try
	new myclass {
		let us have some errors
		p1 { ? self}
		k {		# Error
		}	
	}
catch
	? "1 - BraceError() comes before try/catch/done"
	? "2 - BraceError() doesn't handle opening braces errors"
	? "3 - Try/catch can handle them!"
done

class myclass

	func braceerror
		? :good

class point x y z