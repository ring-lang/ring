load "tests\weblib.nova"

Import System.Web

website = "nice.test"

func main
	t = clock()
	for x = 1 to 1000
	testtemplate()
	see " X = " + x + nl
	next
	see "Time " + (clock() - t) + nl
Func TestTemplate

	o1 = new bookscontroller { gostart() }

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

		cTemp = Template("tests\mytemplate.html",self)

		new Page 
		{ 			
			boxstart(30)
				text( "Test Templates " )  			
				newline()
			theend()
			link(website,"back") 	
			text(cTemp) 
			print() 
		} 


Class books title content