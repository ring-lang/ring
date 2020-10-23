#!ring -cgi
load "weblib.ring"
import system.web

new page{
	title = "Home Page"
	my_v = new my_var
	cTemp = template( "index.html" , my_v )
	html( cTemp )

}

class my_var
	name = "Ahmed"
	numbers = [133, 155, 977]
