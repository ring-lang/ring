#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "profile"
	title = "Profile"

	func start()

		if aPageVars['is_login'] 
			user = get_user(aPageVars['cookie_login_user'])
			if type(user) = "LIST"

				aPageVars['first_name_show']       = user['first_name']
				aPageVars['last_name_show']        = user['last_name']
				aPageVars['address_show']          = user['address']
				aPageVars['address2_show']         = user['address2']
				aPageVars['city_show']             = user['city']
				aPageVars['state_show']            = user['state']
				aPageVars['zip_show']              = user['zip']
				aPageVars['email_show']            = user['email']
				aPageVars['username_show']         = user['username']
				aPageVars['password_show']         = "_iamnotchangepassword_"

			ok
		ok
		cTemp = getPage( "templates/profile.html" , self )
		new hassounaPage{

			html(cTemp)

			if isNameFound("btnlogin")
				redirect("signin.ring")
			ok

			if IsNameFound("btnsave")
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
				err      = ""
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
				if err = ""
					strChangePass = ""
					if pass != "_iamnotchangepassword_"
						strChangePass = ", password='" + sha256(pass) + "'"
					ok
					strUpdate = "UPDATE " + '"user"' + " SET " +
									"first_name='"   + fname    + "', " +
									"last_name='"    + lname    + "', " +
									"address='"      + address  + "', " +
									"address2='"     + address2 + "', " +
									"city='"         + city     + "', " +
									"state='"        + state    + "', " +
									"zip='"          + zip      + "'"   + 
									strChangePass    + 
									" WHERE "        +
									"username='"     + aPageVars["cookie_login_user"] + "'"

					if run(strUpdate)=1
						if strChangePass != ""
							login(aPageVars["cookie_login_user"], pass)
						ok
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


