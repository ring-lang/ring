class program
	menu
	func getmenu 
		return new menu

class menu 

	aItems = []

	func braceexpreval value
		if isstring(value)
			if trim(value)=NULL return ok
			aItems + value 
		ok

	func braceend
		x = 1
		for item in aItems
			? "" + x + " - " + item
			x++
		next
		? "Option: " give nOption
		cOption = aItems[0+nOption]
		eval(cOption+"()")
		
	func braceerror 
		if substr(cCatchError,"R24")
			cName = substr(cCatchError,substr(CCatchError,":")+1)
			cName = substr(cName,substr(cName,":")+1)
			cName = trim(cName)
			braceexpreval(cName)
		ok
