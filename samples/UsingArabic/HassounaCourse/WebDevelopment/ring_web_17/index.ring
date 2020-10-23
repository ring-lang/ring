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
			html('<h1>Full Name is: ' + name + '</h1>')
			html('<h1>Address is  : ' + address + '</h1>')
			html('<h1>Phone is    : ' + phone + '</h1>')
			html('<h1>Email is    : ' + email + '</h1>')
			html('<h1>Username is : ' + user + '</h1>')
			html('<h1>Password is : ' + pass + '</h1>')
			html('<h1>Accept Terms: ' + terms + '</h1>')
		}
