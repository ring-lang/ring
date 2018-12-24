x = new sales.customers
x.hello()

Package Sales
	
	Class Customers
		func hello
			see "Customers" + nl
			y = new invoices
			y.hello()


Package Sales

	Class base
		func test
			see "welcome" + nl
	
	Class Invoices from base
		func hello
			see "Invoices" + nl
			test()


