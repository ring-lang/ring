Import System.Web

Func TestWebpage

	WebPage() 
	{
		Title = "Using objects to create the Web Page content"
		h1 { text("welcome") }
		link 
		{ 
			Title = "Back" 
			Link  = website 
		}	
		div 
		{
			id = "div1"
			style = stylegradient(30) + stylesize("50%","50%")
			text("Outer Div")
			div 
			{
				id = "div2"
				color = "white"
				backgroundcolor = "green"
				width = "50%"
				height = "50%"
				marginleft = "5%"
				margintop = "5%"
				text("Inner Div")
			}
		}
		div
		{
			id = "div3"
			color = "black"
			backgroundcolor = "silver"
			width = "100%"
			height = "100%"
			text("Form")
			form
			{
				method = "POST"
				Action = "helloworld.ring"
				Table
				{ 
					style = stylewidth("100%") + stylegradient(24)			
					TR 
					{ 
						TD { WIDTH="10%" text("Name : " )  }
						TD { Input { type = "text" } }
					}
					TR
					{
						TD { WIDTH="10%" text("Email : " ) }
						TD { Input { type = "text" } }
					}
					TR 
					{
						TD { WIDTH="10%" text("Password : " ) }
						TD { Input { type = "password" } }
					}
					TR
					{
					
						TD { WIDTH="10%" text("Notes") }
						TD { TextArea { width="100%" rows = 10  cols = 10  text("type text here...") } }
					}
					TR
					{
						TD { WIDTH="10%" text("Gender") }
						TD { 
							select
							 {
					     		   width = "100%"
							   option { text("Male") } 
							   option { text("Female") } 
							 }
						}
					}
					TR
					{
						TD { 	WIDTH="10%" text("Role") }
						TD 
						{
							select
							{ 
							   multiple = "multiple"
						           width = "100%"
							   option { text("student") } 
							   option { text("admin") } 
							 }
						}
					}
				}
				Input { type = "submit" value = "send" }
				Image { src="upload/profile1.jpg" alt="profile"}
				Input { type = "checkbox" value = "Old Member"} text("old member")
				Input { type = "range" min=1 max=100}
				Input { type = "number" min=1 max=100}
				Input { type = "radio" color="black" name="one" value = "one"} text("one")
			}
		}
		div
		{
			color = "white"
			backgroundcolor = "blue"
			width = "100%"			
			UL
			{
				LI { TEXT("ONE") }
				LI { TEXT("TWO") }
				LI { TEXT("THREE") }
			}
		}
		div 
		{
			audio
			{
				src = "horse.ogg"
				type = "audio/ogg"
			}

			video
			{
				 width = 320
				 height = 240
				 src = "movie.mp4"
				 type = "video/mp4" 
			}

			Input
			{
				type = "color"
				value = "#ff0000"
				onchange = "clickColor(0, -1, -1, 5"
			}
		}
	}
