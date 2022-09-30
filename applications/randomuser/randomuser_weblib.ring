#!ring -cgi

#=====================================#
# Random User Application	
# Version for the WebLib
# 2022, Mahmoud Fayed
#=====================================#

load "internetlib.ring"
load "jsonlib.ring"
load "weblib.ring"

import System.Web

cData= download("https://randomuser.me/api")
	
aList= JSON2List(cData)
		
cFirstName = aList[:Results][1][:name][:first]
cLastName  = aList[:Results][1][:name][:last]
cEmail     = aList[:Results][1][:email]
cImageFile = aList[:Results][1][:picture][:large]

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

