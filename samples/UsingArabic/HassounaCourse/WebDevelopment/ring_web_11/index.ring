#!ring -cgi
load "weblib.ring"
import system.web

new my_site{ start() }

class my_site
	lang1 = [1, 'JavaScript', True]
	lang2 = [2, 'Java', True]
	lang3 = [3, 'C#', True]
	lang4 = [4, 'Kotlin', False]
	lang5 = [5, 'Python', true]
	lang6 = [6, 'Ring', true]
	lang7 = [7, 'Go', false]
	langs = [lang1, lang2, lang3, lang4, lang5, lang6, lang7]
	func start()
		cTemp = template("index.html", self)
		new page{
			title = "Home Page"
			html(cTemp)
		}
