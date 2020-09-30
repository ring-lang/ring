x = new sales.customers
x.hello()

Package Sales
	
	Class Customers
		see "hello from the customers class" + nl
		func hello
			see "Customers" + nl
			y = new invoices
			y.o1.test()
			y.hello()

	Class base
		see "hello from the sales.base class" + nl
		o1 = new world2.base
		o1.test()
		func test
			see "welcome" + nl
		func wow
			see "Wow from sales package" + nl
	
	Class Invoices from base
		see "hello from the sales.invoices class" + nl
		func hello
			see "Invoices" + nl
			test()
		func nice
			see "nice " + nl



Package world2

	Class base from invoices
		see "hello from the world2.base class" + nl
		func test
			see "welcome from world2" + nl
			hello() 
			nice()
			wow()
			sonice()

		func nice
			see "Great" + nl

	class invoices from world3.base
		see "hello from the world2.invoices class" + nl
		func hello
			see "Invoices from world2" + nl
		func wow
			see "Wow " + nl

Package world3

	class base
		func sonice
			see " so nice! " + nl