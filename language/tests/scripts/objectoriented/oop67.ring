new myclass {
	eval(`
		try
			? :before
			count {
				? :what
			}
			? :after
		catch
			? "Handle Error (Using  Try/Catch): " + cCatchError
		done 
		? :good
	`)
	? :nice
}
? :done

class myclass
	func braceError
		? "Handle Error (Using BraceError): " + cCatchError