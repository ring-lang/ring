Import System.Web

Func TestTemplate

	new bookscontroller { gostart() }

class bookscontroller

	mybook aBooks		

	func gostart

		mybook = new Books 
		{
			title = "Book Title"
			content = "Book Content"
		}

		aBooks = list(10)

		for x = 1 to len(aBooks)
			aBooks[x] = new Books 
			{
				title = "The Title : " + x 
				content = "The Content : " + x*x
			}
		next	  

		cTemp = Template("mytemplate.html",self)
		 
		new Page 
		{ 			
			boxstart()
				text( "Test Templates" )  			
				newline()
			boxend()
			link([ :url = website, :title = "back" ]) 	
			boxstart()
				text( "The Template content" )  			
				newline()
			boxend()

			html(cTemp)  
		} 

Class books title content