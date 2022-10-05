#=====================================#
# Random User Application	
# Version using HTTPLib & Templates
# 2022, Mahmoud Fayed
#=====================================#

load "internetlib.ring"
load "jsonlib.ring"
load "httplib.ring"

C_TEMPLATEFILE = "template/web_template.html"

? "Start the server..."
oServer = new Server

? "Try localhost:5000/randomuser"
oServer.route(:Get,"/randomuser",:randomuser)

? "Share folder: template"
oServer.shareFolder("template")

? "Listen to port 5000"
oServer.listen("0.0.0.0", 5000)

func randomuser

	cData= download("https://randomuser.me/api")
		
	aList= JSON2List(cData)
			
	cFirstName = aList[:Results][1][:name][:first]
	cLastName  = aList[:Results][1][:name][:last]
	cEmail     = aList[:Results][1][:email]
	cGender    = aList[:Results][1][:gender]
	cImageFile = aList[:Results][1][:picture][:large]

	cHTML = read(C_TEMPLATEFILE)
	cHTML = substr(cHTML,"{{UserName}}",cFirstName + " " + cLastName)
	cHTML = substr(cHTML,"{{Email}}",cEmail)
	cHTML = substr(cHTML,"{{Gender}}",cGender)
	cHTML = substr(cHTML,"{{Photo}}",cImageFile)

	oServer.setContent(cHTML,"text/html")
