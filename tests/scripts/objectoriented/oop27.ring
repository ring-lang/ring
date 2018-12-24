x = new sales.customers
x.hello()

Package Sales
	
	Class Customers
		func hello
			see "Customers" + nl
			y = new invoices
			y.hello()

	Class base
		o1 = new world2.base
		o1.test()
		func test
			see "welcome" + nl
	
	Class Invoices from base
		func hello
			see "Invoices" + nl
			test()


Package world2

	Class base from invoices2
		func test
			see "welcome from world2" + nl
			hello()

	class invoices2
		func hello
			see "Invoices from world2" + nl