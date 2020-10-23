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

			r = 0
			num1 = 0
			num2 = 0
			if aPageVars['num1'] != null and aPageVars['num2'] != null 
				num1 = number(aPageVars['num1'])
				num2 = number(aPageVars['num2'])
			ok

			if aPageVars['btn1'] != null
				r = num1 + num2
			ok

			if aPageVars['btn2'] != null
				r = num1 - num2
			ok

			if aPageVars['btn3'] != null
				r = num1 * num2
			ok

			if aPageVars['btn4'] != null
				if num2=0 num2=1 ok
				r = num1 / num2
			ok

			if aPageVars['btn5'] != null
				if num2=0 num2=1 ok
				r = num1 % num2
			ok

			if r != 0
				html('<hr><h3>Result is: ' + r + '</h3>')
			ok

		}
