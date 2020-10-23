#!ring -cgi
load "hassounaweb.ring"
import system.web

new my_site{ start() }

class my_site

	func start()
		cTemp = template("index.html", self)
		new bootstrapPage{
			title = "Home Page"
			html(cTemp)

			if isNameFound('btnCreateCookie')
				cookie('id',1)
				cookie('name', 'Ahmed Amr')
				cookie('address','Egypt')
				cookie('phone','0123456789')
				cookie('salary',850)
				cookie('current_date', date())
				cookie('favorite_lang','RING')
			ok

			if isNameFound('btnCreateCookieLong')
				cCookies += get_cookie_longtime('os','Windows')
				cCookies += get_cookie_longtime('lang','en')
			ok

			if isNameFound('btnReadCookie')
				for x in getCookies()
					html( '<h3>' + x[1] + ' = ' + x[2] + '</h3><br>' )
				next
			ok

			if isNameFound('btnDelCookie')
				for x in getCookies()
					cCookies += get_cookie_del(x[1])
				next
			ok

			html('<a href="index.ring?name=' + URLEncode('-*{Mahmoud}*-') + '&salary=860">URL Encode</a>')

		}
