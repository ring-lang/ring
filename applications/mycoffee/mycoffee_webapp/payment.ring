#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "payment"
	title = "Payment"
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
		
		cTemp = getPage( "templates/payment.html" , self )
		new hassounaPage{

			html(cTemp)

			if not is_login()
				redirect("index.ring")
			ok

			if IsNameFound("btnpayment")
				sh_address    = MyVal(aPageVars['ship_address'])
				sh_phone    = MyVal(aPageVars['ship_phone'])
				card_num  = MyVal(aPageVars['card_number'])
				expire = MyVal(aPageVars['expire'])
				sec_code     = MyVal(aPageVars['security_code'])
				err      = ""
				if trim(sh_address)    = '' err += "Please enter shipment address<hr>" ok
				if trim(sh_phone)    = '' err += "Please enter shipment phone<hr>" ok
				if trim(card_num)  = '' err += "Please enter card number<hr>" ok
				if trim(expire) = '' err += "Please enter expire<hr>" ok
				if trim(sec_code)     = '' err += "Please security code<hr>" ok 
				check_order = len(get_data('select id from payment where order_id=' + this.ord_id))
				if check_order > 0     err += "This order is finished<hr>" ok
				if err = ""
					strInsert = "insert into payment values(DEFAULT, " + this.ord_id + ", '" + sh_address + "', '" + sh_phone + "', '" + card_num + "', to_date('" + expire + "', 'MM/YY'), '" + sec_code + "')"  

					if run(strInsert)=1
						run("UPDATE " + '"order"' + " SET is_finished=TRUE WHERE id=" + this.ord_id)
						redirect("ok.ring")
					else
						add_err("Error")
					ok
				else
					add_err(err)
				ok

			else
				del_err()
			ok

		}


