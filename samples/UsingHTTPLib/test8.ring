load "httplib.ring"
load "weblib.ring"
import System.Web

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/form"
oServer.route(:Get,"/form",:form)
oServer.route(:Get,"/formresponse",:formresponse)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func form

	oPage = New HTMLPageFunctions
	{
		Title = "Test HTTP Get"
		divstart([ :style = StyleSizeFull() ] )
			boxstart()
				text( "Test HTTP GET" )
				newline()
			boxend()
			divstart([ :style = Styledivcenter("600px","550px") +
						StyleGradient(21) ])
				divstart([:style = stylefloatleft() + stylesize("100px","100%") +
							StyleColor("black") + StyleGradient(58)])
					formstart("/formresponse")
						tablestart([ :style = stylesize("65%","90%") +
									stylemarginleft("35%") +
									stylemargintop("30%") ])
							rowstart([])
								cellstart([ ])
									text ( "Name : "  )
								cellend()
								cellstart([])
									cTextboxStyle = StyleMarginLeft("5%") +
											StyleWidth("250px") +
											StyleColor("black") +
											StyleBackColor("white")
									textbox([ :name = "Name", :style = cTextboxStyle ] )
								cellend()
							rowend()
							rowstart([])
								cellstart([])
									text ( "Address : " )
								cellend()
								cellstart([ ])
									textbox([ :name = "Address", :style = cTextboxStyle] )
								cellend()
							rowend()
							rowstart([])
								cellstart([])
								text ( "Phone : " )
								cellend()
							cellstart([  ])
								textbox([ :name = "Phone", :style = cTextboxStyle ])
							cellend()
							rowend()
							rowstart([])
								cellstart([])
									text ( "Age : "  )
								cellend()
								cellstart([  ])
									textbox([ :name = "Age", :style = cTextboxStyle ])
									cellend()
							rowend()
							rowstart([])
								cellstart([])
									text ( "City: " )
								cellend()
								cellstart([  ])
									listbox([ :name = "City", :items = ["Cairo","Riyadh","Jeddah"],
											 :style = stylemarginleft("5%") + stylewidth("400px") ] )
								cellend()
							rowend()
							rowstart([])
								cellstart([])
									text ( "Country : " )
								cellend()
								cellstart([   ])
									combobox([ :name = "Country",
											 :items = ["Egypt","Saudi Arabia","USA"],
											 :style = stylemarginleft("5%") +
													  stylewidth("400px")+
													  stylecolor("black")+
													  stylebackcolor("white")+
													  stylefontsize("14px") ])
								cellend()
							rowend()
							rowstart([])
								cellstart([])
									text ( "Note : " )
									cellend()
									cellstart([   ])
										editbox([ :name = "Notes",
											:style = stylemarginleft("5%") +
													 stylesize("400px","100px")+
													 stylecolor("black")+
													 stylebackcolor("white") ,
											:value = "write comments here..." ] )
									cellend()
								rowend()
							rowstart([])
								cellstart([])
								cellend()
								cellstart([   ])
									submit([ :value = "Send" , :Style = stylemarginleft("5%") ])
								cellend()
							rowend()
						tableend()
					formend()
				divend()
			divend()
		divend()
	}
	oServer.setHTMLPage(oPage)

func formresponse

	oPage = New HTMLPageFunctions
	{
		divstart([ :style = styledivcenter("800px","500px") ])
			boxstart()
				text ( "HTTP GET Response" )  newline()
			boxend()
			divstart([ :style = stylefloatleft()+stylewidth("10%")+
					  stylecolor("black")+stylegradient(58) ])
				newline()
				text ( "Name : "   )
				newline() newline()
				text ( "Address : "  )
				newline() newline()
				text ( "Phone : "   )
				newline() newline()
				text ( "Age : "   )
				newline() newline()
				text ( "City : "   )
				newline() newline()
				text ( "Country : "   )
				newline() newline()
				text ( "Note : "   )
				newline() newline()
			divend()
			divstart([ :style = stylefloatleft()+stylewidth("90%")+
					  stylecolor("black")+stylegradient(47) ])
				divstart([ :style = stylefloatleft() + stylewidth("1%") ])
					newline()
				divend()
				divstart([ :style = stylefloatleft() + stylewidth("95%") ])
					newline()
					text ( oServer["Name"] )
					newline() newline()
					text ( oServer["Address"] )
					newline() newline()
					text ( oServer["Phone"] )
					newline() newline()
					text (  oServer["Age"] )
					newline() newline()
					text ( oServer["City"] )
					newline() newline()
					text (oServer["Country"] )
					newline() newline()
					text ( oServer["Notes"] )
					newline() newline()
				divend()
			divend()
		divend()
	}

	oServer.setHTMLPage(oPage)
