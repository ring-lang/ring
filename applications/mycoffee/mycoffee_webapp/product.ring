#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page   = "product"
	title  = "Product"

	func start()
		
		cTemp = getPage( "templates/product.html" , self )
		new hassounaPage{


			html(cTemp)

			if not IsNameFound("pro_id")
				redirect("index.ring")
			ok

			if IsNameFound("btn_add_to_favorite") 
				if is_login() 
					username = aPageVars['cookie_login_user'] 
					user_id  = get_user_id(username)
					pro_id   = aPageVars['pro_id']
					add_fav_pro(user_id, pro_id)
					redirect("products_favorite.ring")
				ok
			ok

			if IsNameFound("btn_add_to_cart")

				if is_login()
					ord_id = get_order_not_finished(aPageVars['cookie_login_user'])
					if ord_id = -1 
						add_order(aPageVars['cookie_login_user'])
						ord_id = get_order_not_finished(aPageVars['cookie_login_user'])
					ok
					pro_id = aPageVars['pro_id']
					qty    = aPageVars['qty']
					pro = get_product(pro_id)
					price = pro['price']
					is_added = add_order_details(ord_id, pro_id, qty, price)
					if is_added 
						redirect("cart.ring")
					ok
				ok
			ok


		}


