Import System.Web

Func TestGet

	New Page
	{

		Title = "Test HTTP Get"

		divstart([ :style = StyleSizeFull() ] )

			boxstart()
				text( "Test HTTP GET مثال الحصول على البيانات من الرابط" )
				newline()
			boxend()	

			link([ :url = website , :title = "back"])

			divstart([ :style = styledivcenter("600px","550px") + StyleGradient(21) ])

				divstart([ :style = stylefloatleft() + stylesize("100px","100%") + stylecolor("black") + stylegradient(58)  ])
					formstart(website)
					hidden("page",2)

						tablestart([ :style = stylesize("65%","90%") + stylemarginleft("35%") + stylemargintop("30%") ])
						rowstart([]) 
							cellstart([ ])
								text ( "Name : "  )  
							cellend() 
							cellstart([])
								cTextboxStyle = stylemarginleft("5%") + stylewidth("250px") + stylecolor("black") + stylebackcolor("white")
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
								   :items = ["Egypt","Saudia Arabia","USA"],
								   :style = stylemarginleft("5%") + stylewidth("400px")+stylecolor("black")+stylebackcolor("white")+
								   stylefontsize("14px") ])
							cellend()
						rowend()
						rowstart([]) 
							cellstart([])
								text ( "Note : " )    	 
							cellend() 
							cellstart([   ])
								editbox([ :name = "Notes", 
								  :style = stylemarginleft("5%") + stylesize("400px","100px")+stylecolor("black")+stylebackcolor("white") , 
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


Func TestGetResponse

	New Page
	{


		divstart([ :style = styledivcenter("800px","500px") ])

			boxstart()

				text ( "HTTP GET Response عرض البيانات المرسلة عبر الرابط" )	newline()
				
			boxend()

			
			divstart([ :style = stylefloatleft()+stylewidth("10%")+stylecolor("black")+stylegradient(58) ])

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

			divstart([ :style = stylefloatleft()+stylewidth("90%")+stylecolor("black")+stylegradient(47) ])

				divstart([ :style = stylefloatleft() + stylewidth("1%") ])
					newline()
				divend()

				divstart([ :style = stylefloatleft() + stylewidth("95%") ])
					newline()
					text ( aPageVars["Name"] )
					newline() newline()
					text ( aPageVars["Address"] )
					newline() newline()
					text ( aPageVars["Phone"] )
					newline() newline()
					text (  aPageVars["Age"] )
					newline() newline()
					text ( aPageVars["City"] )
					newline() newline()
					text (aPageVars["Country"] )
					newline() newline()
					text ( aPageVars["Notes"] )
					newline() newline()
				divend()

			divend()


			link([ :url = website+"?page=1", :title = "back"])
	 		newline() 	

		divend()
		
	}

