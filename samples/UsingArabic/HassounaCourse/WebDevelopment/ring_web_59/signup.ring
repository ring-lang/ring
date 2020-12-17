#!ring -cgi
load "db.ring"
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "signup"
	title = "Sign Up"

	func start()

		cTemp = getPage( "templates/signup.html" , self )

		new hassounaPage{

			html(cTemp)
  
			if IsNameFound("btnsignup")
				fName    = MyVal(aPageVars['first_name'])
				lName    = MyVal(aPageVars['last_name'])
				address  = MyVal(aPageVars['address'])
				address2 = MyVal(aPageVars['address2'])
				city     = MyVal(aPageVars['city'])
				state    = MyVal(aPageVars['state'])
				zip      = MyVal(aPageVars['zip'])
				email    = MyVal(aPageVars['email'])
				user     = MyVal(aPageVars['username'])
				pass     = MyVal(aPageVars['password'])
				terms    = MyVal(aPageVars['terms'])
				err      = ""
				if terms != "on"       err += "Please agree of the terms<hr>" ok
				if trim(fname)    = '' err += "Please enter first name<hr>" ok
				if trim(lname)    = '' err += "Please enter last name<hr>" ok
				if trim(address)  = '' err += "Please enter address<hr>" ok
				if trim(address2) = '' err += "Please enter address 2<hr>" ok
				if trim(city)     = '' err += "Please enter city<hr>" ok
				if trim(state)    = '' err += "Please enter state<hr>" ok
				if trim(zip)      = '' err += "Please enter zip<hr>" ok
				if trim(email)    = '' err += "Please enter email<hr>" ok
				if trim(user)     = '' err += "Please enter username<hr>" ok
				if trim(pass)     = '' err += "Please enter password<hr>" ok
				check_user = len(get_data('select id from "user" where username=' + "'" + user + "'"))
				check_email = len(get_data('select id from "user" where email=' + "'" + email + "'"))
				if check_user  > 0     err += "This username already exists<hr>" ok
				if check_email > 0     err += "This email already exists<hr>" ok
				if err = ""
					strInsert = "insert into " + '"user"' + 
									" values(DEFAULT, '"   + 
									fName    + "', '"      +
									lName    + "', '"      +  
									address  + "', '"      +  
									address2 + "', '"      +  
									city     + "', '"      +  
									state    + "', '"      +  
									zip      + "', '"      +  
									email    + "', '"      +  
									user     + "', '"      +  
									pass     + "', "       +  
									"CURRENT_TIMESTAMP, "  +
									"DEFAULT, False, True )"
					if run(strInsert)=1
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


