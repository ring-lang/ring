#!ring -cgi
load "hassounaweb.ring"
import system.web

isFound('btn1')
new my_site{ start() }

class my_site

	func start()
		cTemp = template("index.html", self)
		new bootstrapPage{
			title = "Home Page"
			html(cTemp)

			if isFound('btn1')

				fileUrl = upload( self , 'file1' )
				if fileUrl != null					
					html('<hr>')
					html('<a href="' + fileUrl + '" target="_blank">Goto File</a>')
					html('<hr>')
					html('<img src="' + fileUrl + '" style="width:350px;height:250px" >')
					html('<hr>')
				ok
			ok

		}
