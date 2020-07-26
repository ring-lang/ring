load "magicmenulib.ring"

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

