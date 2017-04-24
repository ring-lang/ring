Import system.web

func testgradient

	new page
	{

		boxstart()
			text("StyleGradient() Function")
		boxend()
		 
		for x = 1 to 60
			
			divstart([ :id = x , :align = "center" , 
				   :style = stylefloatleft() + stylesize(string(100/60*6)+"%","100px") + stylegradient(x) ])
				h1(x)
			divend()
				 
 		next

	}