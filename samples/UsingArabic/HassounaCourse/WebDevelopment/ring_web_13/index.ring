#!ring -cgi
load "weblib.ring"
import system.web

new my_site{ start() }

class my_site
	e1 = [:id=1, :name='Adel',  :salary=1900, :is_active=true]
	e2 = [:id=2, :name='Omar',  :salary=1800, :is_active=true]
	e3 = [:id=3, :name='Amr',   :salary=1700, :is_active=true]
	e4 = [:id=4, :name='Ali',   :salary=1600, :is_active=true]
	e5 = [:id=5, :name='Ezzat', :salary=1500, :is_active=false]
	e6 = [:id=6, :name='Yaser', :salary=1400, :is_active=true]
	e7 = [:id=7, :name='Ramy',  :salary=1300, :is_active=false]
	e8 = [:id=8, :name='Ezz',   :salary=1200, :is_active=false]
	e9 = [:id=9, :name='Gamal', :salary=1100, :is_active=true]
	employees = [e1, e2, e3, e4, e5, e6, e7, e8, e9]
	func start()
		cTemp = template("index.html", self)
		new bootstrapPage{
			title = "Home Page"
			html(cTemp)
		}
