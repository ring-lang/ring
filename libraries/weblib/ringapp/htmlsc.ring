Import System.web

func testhtmlsc

	New Page
	{

		boxstart()
			text("HTML Special Characters")
			newline()
		boxend()

		link([ :url = website, :link = "back" ]) 	
		newline()

		text('
			<html>
				<body>
					<p> "hello world" </p>
				</body>
			</html>
		')

	}


