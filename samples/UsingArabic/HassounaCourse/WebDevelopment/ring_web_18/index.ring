#!ring -cgi
load "weblib.ring"
import system.web

new my_site{ start() }

class my_site
	func start()
		cTemp = template("index.html", self)
		new bootstrapPage{
			title = "Home Page"
			html(cTemp)
			name = aPageVars['name']
			address = aPageVars['address']
			phone = aPageVars['phone']
			email = aPageVars['email']
			user = aPageVars['user']
			pass = aPageVars['pass']
			terms = aPageVars['terms']
			if name != null
				html('<h1>Full Name is: ' + name + '</h1>')
			ok
			if address != null 
				html('<h1>Address is  : ' + address + '</h1>')
			ok
			if phone != null
				html('<h1>Phone is    : ' + phone + '</h1>')
			ok
			if email != null
				html('<h1>Email is    : ' + email + '</h1>')
			ok
			if user != null
				html('<h1>Username is : ' + user + '</h1>')
			ok
			if pass != null
				html('<h1>Password is : ' + pass + '</h1>')
			ok
			if terms != null
				html('<h1>Accept Terms: ' + terms + '</h1>')
			ok
			html('<h1>' + aPagevars['btncreateaccount'] + '</h1>')
		}
