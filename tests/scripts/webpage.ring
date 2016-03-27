Load "tests\weblib.ring"

Import System.Web

website = "localhost"

func main

	see webpage()
	WebPage() 
	{
		aObjs = []
		Title = "Web Page content using objects"

		Link() 	
		{ 
			Title = "Back" 
			Link  = website 
		}		

		Div() 
		{
			color = "white"
			backcolor = "Purple"
			width = "50%"
			height = "50%"
			text("Welcome to the Ring programming language")
			Div() 
			{
				color = "white"
				backcolor = "green"
				width = "50%"
				height = "50%"
				text("Welcome to the Ring programming language")
			}
		}

		Div() 
		{
			color = "white"
			backcolor = "red"
			width = "50%"
			height = "50%"
			text("Welcome to the Ring programming language")
		}


	}

	