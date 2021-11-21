Import System.Web

Func TestPost

	New Page 
	{

		boxstart()
			text( "Post Test")
		 	newline()
		boxend()

		link([ :url = website, :title = "back" ]) 	
		newline() 		

		divstart([:style=StyleFloatLeft()+StyleWidth("100px") ])
			newline()
			text( "Number1 : " )  		newline() newline()
			text( "Number2 : " ) 		newline() newline()
		divend()

		formpost(website)

			hidden("page",4)

			divstart([ :style = styleFloatLeft()+StyleWidth("200px") ])
				newline()
				textbox([ :name = "Number1" ]) 	newline() newline()
				textbox([ :name = "Number2" ]) 	newline() newline()
				submit([ :value = "Send" ] )
			divend()

		formend()
		
		cDivStyle = styleFloatLeft()+stylewidth("400px")

		divstart([ :style = cDivStyle ])
			video([ :width = 320, :height = 240, :file = "movie.mp4", :type = "video/mp4" ])
		divend()

		divstart([:style=cDivStyle])
			audio([ :file = "horse.ogg", :type = "audio/ogg" ])
		divend()

		divstart([ :style = cDivStyle ])
			getcolor([ :id = "getcolor" , :value = "#0000ff"])
			textbox([ :type = "password" , :name = "pass" , :style = stylesize("100px","20px") ])
		divend()

		divstart([:style=cDivStyle])
			radio([ :name = "sex", :value = "male", :status = "checked" , :text = "male" ])
			radio([ :name = "sex", :value = "female", :text = "female" ])
		divend()
	
		divstart([:style=cDivStyle])
			checkbox([ :name = "check1", :Value = "important", :status = "checked", :text ="important customer" ])
			newline()
			checkbox([ :name = "check2", :Value = "remind" , :text = "Remind me later about this customer" ])
			ButtonLink([ :value = "Add", :link = website , :style = stylegradient(20) ] )
			Button([ :value = "Edit" , :onclick = "alert('edit')" , :style = stylegradient(34) ])
			Button([ :value = "Find" , :onclick = "alert('find')" , :style = stylegradient(36) ])
		divend()

		divstart([:style=cDivStyle])
			spinner([ :name = "test1", :min = 1, :max = 5 ])
			slider([ :name = "Test2", :min = 1, :max = 100 ])
		divend()
	}


Func TestPostResponse

	New Page 
	{
		boxstart()
			text( "Post Result" )
			newline()
		boxend()
		link([ :url = website+"?page=3", :title = "back" ]) newline() 	
		divstart([ :style = styleFloatLeft()+styleWidth("200px") ])
			newline()
			text( "Number1 : " + aPageVars["Number1"] )  	
			newline() newline()
			text( "Number2 : " + aPageVars["Number2"] )  	
			newline() newline()
			text( "Sum : " + (0 + aPageVars["Number1"] + aPageVars["Number2"] ) )
			newline()
		divend()		
	}	
