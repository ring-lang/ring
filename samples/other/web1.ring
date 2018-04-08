#!ring -cgi
Load "weblib.ring"
Import System.Web
WebPage() {
	Title = "Hello, World"
	div {	
		style = StyleGradient(30)
		text("Hello, World!")
	}
	div {	
		style = StyleGradient(24)
		text("Count from 1 to 10")
		ul {
			for x = 1 to 10 {
				li { text(x) }
			}
		}
	}
	
}
