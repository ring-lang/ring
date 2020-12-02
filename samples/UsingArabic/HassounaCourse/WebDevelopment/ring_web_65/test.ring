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
				//text( order_is_found(1) )
				//text( order_is_finished(1) )
				//text( is_found_order_not_finished(3) )
				//text( get_order_not_finished(3) )
				//text( add_order_details( 1, 2, 1, 20 ) )
				//text( order_details_is_found(1, 2) )
				//text( get_qty_for_order_details(1,2) )
				text( edit_qty_order_details(1,2,5) )
			ok

		}


