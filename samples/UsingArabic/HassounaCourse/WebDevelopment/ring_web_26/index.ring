#!ring -cgi
load "weblib.ring"
load "stdlib.ring"
import system.web

new my_site{ start() }

class my_site

	func isFound(elName)
		found = false
		for x in aPageVars
			if find(x,elName)
				found = true
				exit
			ok
		next
		return found

	func start()
		cTemp = template("index.html", self)
		new bootstrapPage{
			title = "Home Page"
			html(cTemp)

			if this.isFound('btn1')
				cFile = 'file1'
				if aPageVars[cFile] != char(13)
					cUploadFolder = '/uploads/'
					cUploadPath = currentdir() + cUploadFolder
					cFileName = cUploadPath + self.getFileName(aPageVars,cFile)
					write(cFileName, aPageVars[cFile])
					system('chmod a+x ' + cFileName)
					fileUrl = cUploadFolder + self.getFilename(aPageVars,cFile)
					html('<hr>')
					html('<a href="' + fileUrl + '" target="_blank">Goto File</a>')
					html('<hr>')
					html('<img src="' + fileUrl + '" style="width:350px;height:250px" >')
					html('<hr>')
				ok

			ok

		}
