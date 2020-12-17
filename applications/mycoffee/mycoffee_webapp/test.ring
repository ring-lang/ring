#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "test"
	title = "Test"

	func start()
		
		cTemp = getPage( "test.html" , self )
		new hassounaPage{

			html(cTemp)

			if isNameFound('btnlogin')
				login("wael","123456")
			ok

			if isNameFound('btnlogout')
				logout()
			ok

			if IsNameFound("btn_add_order")
				Text( add_order("wael") )
				text( add_order("ahmed") )
			ok

			if IsNameFound("btn_test")
				text( edit_qty_order_details(1,2,5) )
			ok

		}


