#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	page  = "signin"
	title = "Sign In"

	func start()

		cTemp = getPage( "templates/signin.html" , self )
		new hassounaPage{

			html(cTemp)

			if isNameFound('btnlogin')

				user = MyVal(aPageVars['user'])
				pass = MyVal(aPageVars['pass'])

				if aPageVars['rememberme']="on"

					if login_long(user, pass)
						redirect("signin.ring")
						del_err()
					else
						add_err("Username or Password invalid")
					ok

				else
	
					if login(user, pass)
						redirect("signin.ring")
						del_err()
					else
						add_err("Username or Password invalid")
					ok

				ok


			else
					del_err()
			ok


			if isNameFound("btnlogout")
				logout()
				redirect("index.ring")
			ok

		}


