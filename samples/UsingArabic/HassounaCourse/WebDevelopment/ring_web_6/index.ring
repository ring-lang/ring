#!ring -cgi
load "weblib.ring"
import system.web

new page{
	title = "Home Page"
	cTemp = template( "index.html" , null )
	html( cTemp )
	html("<h2>Hello</h2>")
	text("<html>")
	html( htmlspecialchars("<hr>") )

}
