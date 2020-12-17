#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "cart"
	title = "Cart"
	order_details = []
	total = 0
	full_name = ""

	if aPageVars['is_login'] 
		usr = get_user(aPageVars['cookie_login_user'])
		full_name = usr['first_name'] + ' ' + usr['last_name']
		ord_id = get_order_not_finished(aPageVars['cookie_login_user'])
		order_details = get_order_details(ord_id)
		for x in order_details
			total += Number( x['subtotals'] )
		next
	ok

	func start()
		
		
		cTemp = getPage( "templates/cart.html" , self )
		new hassounaPage{

			html(cTemp)

			if not is_login()
				redirect("index.ring")
			ok

			if IsNameFound("btnadd")
				add_qty_order_details(this.ord_id, aPageVars['btnadd'])
				redirect("cart.ring")
			ok

			if IsNameFound("btnsub")
				sub_qty_order_details(this.ord_id, aPageVars['btnsub'])
				redirect("cart.ring")
			ok

			if IsNameFound("btndel")
				remove_order_details(this.ord_id, aPageVars['btndel'])
				redirect("cart.ring")
			ok

		}


