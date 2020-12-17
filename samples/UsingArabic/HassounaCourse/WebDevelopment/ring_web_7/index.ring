#!ring -cgi
load "weblib.ring"
import system.web

new page{
	title = "Home Page"
	cTemp = template( "index.html" , null )
	html( cTemp )

}
