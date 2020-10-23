#!ring -cgi
load "weblib.ring"
import system.web

webpage(){

h1{	text("Hello web using ring") }

form{
	for x in 1:5
		input{ 
			type="number"
			name="num"+x 
			value=x
		}
		html("<br><br>")
	next
}

}
