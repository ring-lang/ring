load "tests/weblib.ring"

import system.web

testgradient()

func testgradient

	new page
	{

		boxstart()
			text("StyleGradient() Function")
		boxend()
		 
		for x = 1 to 60
			
				cStyle = "float:left ;width:"+(100/60*6)+"% ; height:100px ; " + stylegradient(x)
		
				divstart([ :id = x , :align = "center" , :style = "float:left ;width:"+(100/60*6)+"% ; height:100px ; " + stylegradient(x) ])
					h1(x)
				divend()
				 
 		next

	}