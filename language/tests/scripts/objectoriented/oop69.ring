try
	new myclass {
		eval(`
			? :before
			count {
				? :what
				? self
				count { }
			}
			? :after
		`)
	}
catch
	? "Handle Error (Using  Try/Catch): " + cCatchError
done 

? :done

class myclass
	func braceError
		? "Handle Error (Using BraceError): " + cCatchError
		return new point {x=10 y=20 z=30}

class point x y z