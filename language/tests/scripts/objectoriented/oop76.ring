x = new obj {
	try
		test(x)
	catch
		? "Can't kill opened object!"
	done
	o = new myclass 
	try
		o.test(x)
	catch
		? "Can't kill opened object!"
	done
	o {
		try
			test(x)
		catch
			? "Can't kill opened object!"
		done
	}
}

func test v
	v = null

class myclass
	
	func test v
		v = null

class obj