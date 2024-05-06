/*
**
** Web Server (For Testing)
**
*/

load "httplib.ring"

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/attendance"
oServer.route(:Get,"/ins",:Ins )
oServer.route(:Get,"/subject",:Subject )
oServer.route(:Get,"/attendance",:Attendance)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func ins  

	oServer.setContent("Fayed", "text/plain")

func subject  

	oServer.setContent("Programming", "text/plain")

func attendance

	nAttendance = 50 + random(50)
	oServer.setContent(""+nAttendance, "text/plain")
