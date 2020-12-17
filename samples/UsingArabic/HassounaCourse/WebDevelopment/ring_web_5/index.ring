#!ring -cgi
load "weblib.ring"
import system.web

new page{

	divstart([:style = styleFontSize(50) + styleColor('red') ])
		text("Hello")
		textBox([
				:style = styleFontSize(30) + styleColor('navy'),
				:value = "Hello"
				])
	divend()

}
