new program {
	menu {
		Customers	Invoices
		Reports		System
		Shutdown
	}
}

func customers
	? "Customers Function!"

func Invoices
	? "Invoices Function!"
	
func Reports
	? "Reports Function!"

func System
	? "System Function!"

func shutdown
	bye

class program
	menu
	func getmenu 
		return new menu

class menu 

	aItems = []

	func braceexpreval value
		if isstring(value)
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
		
