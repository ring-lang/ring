load "stdlibcore.ring"
load "weblib.ring"

import System.Web

		
cFirstName = "Test1"
cLastName  = "Test2"
cEmail     = "Test3"
cImageFile = "Test4"

new Page
{
	title = "Random User"
	h1("Random User Application")
	image( [ :url = cImageFile , :alt = :image  ] )
	NewLine() NewLine()
	NewLine()
	Text(cFirstName + " " + cLastName)
	NewLine()
	Text("Email: " + cEmail)
	NewLine() NewLine()
	link([ :url = JustFileName(filename()), :title = "Get Random User" ])
}

