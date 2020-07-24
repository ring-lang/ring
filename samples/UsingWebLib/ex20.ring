#!ring -cgi

Load "weblib.ring"
Import System.Web

Func Main
	New Page
	{

		boxstart()
			text("StyleGradient() Function")
		boxend()
		 
		for x = 1 to 60
			
			divstart([ :id = x , :align = "center" , 
				   :style = stylefloatleft() + stylesize(string(100/60*6)+"%","50px") + stylegradient(x) ])
				h3(x)
			divend()
				 
 		next

	}
