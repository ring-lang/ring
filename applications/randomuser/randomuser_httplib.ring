#=====================================#
# Random User Application	
# Version using WebLib & HTTPLib 
# 2022, Mahmoud Fayed
#=====================================#

load "internetlib.ring"
load "jsonlib.ring"
load "weblib.ring"
load "httplib.ring"

import System.Web

cFirstName = ""
cLastName  = ""
cEmail     = ""
cGender    = ""
cImageFile = ""

? "Start the server..."
oServer = new Server

? "Try localhost:5000/randomuser"
oServer.route(:Get,"/randomuser",:randomuser)

? "Listen to port 5000"
oServer.listen("0.0.0.0", 5000)

func GetUserData 

	cData= download("https://randomuser.me/api")
		
	aList= JSON2List(cData)
			
	cFirstName = aList[:Results][1][:name][:first]
	cLastName  = aList[:Results][1][:name][:last]
	cEmail     = aList[:Results][1][:email]
	cImageFile = aList[:Results][1][:picture][:large]

func randomuser

	GetUserData()

	oPage = New HTMLPageFunctions
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
		link([ :url = "/randomuser", :title = "Get Random User" ])
	}

	oServer.setHTMLPage(oPage)
