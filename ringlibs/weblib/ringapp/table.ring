Import System.Web

func testtables

	New Page
	{

		divstart([ :style = styledivcenter("400px","500px") ] )

			style(styletable() + styletablerows("t01"))
	
			tablestart([ :id = :t01 , :style = stylewidth("100%") ])

				rowstart([]) 
					headerstart([]) text("Number") headerend()
					headerstart([]) text("square") headerend()
					headerstart([]) text("options") headerend()
				rowend() 

				for x = 1 to 10
					rowstart([])
						cellstart([]) text(x) cellend()
						cellstart([]) text(x*x) cellend()
						cellstart([])
							link([ :url = website, :title = "more" ])
						cellend()
					rowend()
				next

			tableend()

		divend()
	}