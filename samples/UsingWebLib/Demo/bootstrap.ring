Import system.web

Func testbootstrap

	new BootstrapPage {

		divstart([ :class = "container" ])

		 	divstart([ :class = "jumbotron"  ])
				h1("Bootstrap Page")
			divend() 

			divstart([ :class = :row ])	

				divstart([ :class = "col-sm-4" ])
					h3("Welcome the the Ring programming language")
					p([ :text = "Using a scripting language is very fun!" ])
				divend()

				divstart([ :class = "col-sm-4" ])
					h3("Welcome the the Ring programming language")
					p([ :text = "using a scripting language is very fun!" ])
				divend()

				divstart([ :class = "col-sm-4" ])
					h3("Welcome the the Ring programming language")
					p([ :text = "using a scripting language is very fun!" ])
				divend()

			divend() 	

		divend()

	}


Func testbootstrap2

	BootStrapWebPage()
	{
		div
		{
			classname = :container
			div
			{
				classname = :jumbotron
				H1 { 	text("Bootstrap Page") 	}
			}

			div
			{
				classname = :row
				for x = 1 to 3
					div
					{
						classname = "col-sm-4"
						H3 { html("Welcome the the Ring programming language") }
						P  { html("Using a scripting language is very fun!") }
					}
				next 
			}

			div
			{
				classname = :row
				div
				{
					classname = "col-sm-4"
					Button
					{						
						classname = "btn btn-info btn-lg"
						datatoggle= "modal"
						datatarget = "#myModal"
						text("Open Large Modal")
					}
					
				}
				div
				{
					classname = "col-sm-4"
					Button {  classname = "btn btn-default btn-lg" text("default") }
					Button {  classname = "btn btn-primary btn-md" text("primary") }
					Button {  classname = "btn btn-success btn-sm" text("success") }
					Button {  classname = "btn btn-info btn-xs"    text("info") }
					Button {  classname = "btn btn-warning"        text("warning") }
					Button {  classname = "btn btn-danger"	       text("danger") }
					Button {  classname = "btn btn-link" 	       text("link") }
				}
				div
				{
					classname = "col-sm-4"
					Button {  classname = "btn btn-default btn-block" text("default") }
					Button {  classname = "btn btn-primary btn-block" text("primary") }
					Button {  classname = "btn btn-success btn-block" text("success") }
					Button {  classname = "btn btn-info btn-block"    text("info") }
					Button {  classname = "btn btn-warning btn-block" text("warning") }
					Button {  classname = "btn btn-danger btn-block"  text("danger") }
					Button {  classname = "btn btn-link btn-block"    text("link") }
				}
				div
				{
					classname = "col-sm-4"
					div { classname = "btn-group" 
						button {  classname="btn btn-primary" text("one") }
						button {  classname="btn btn-primary" text("two") }
						button {  classname="btn btn-primary" text("three") }
					}
				}
				div
				{
					classname = "col-sm-4"
					div { classname = "btn-group btn-group-lg" 
						button {  classname="btn btn-primary" text("one") }
						button {  classname="btn btn-primary" text("two") }
						button {  classname="btn btn-primary" text("three") }
					}
				}
				div
				{
					classname = "col-sm-4"
					div { 
						classname = "btn-group-vertical btn-group-lg" 
						button {  classname="btn btn-primary" text("one") }
						button {  classname="btn btn-primary" text("two") }
						button {  classname="btn btn-primary" text("three") }
					}
				}
			}
			

			div { classname="modal fade" id="myModal" role="dialog"			
				div { classname = "modal-dialog modal-lg"
					div { classname="modal-content" 
						div { classname="modal-header"
							button {  classname="close" datadismiss="modal"
								html("&times")
							}
							h4 {	classname="modal-title"
								text("Modal Header")
							}
						}
						div { classname = "modal-body" 
							p { text("This is a large model.") }
						}
						div { classname="modal-footer"
							button { classname = "btn btn-default" datadismiss="modal"
								text("close")
							}
						}
					}
				}
			}
		}	

	}

Func testbootstrap3

	new BootStrapPage
	{

		html(`

<meta charset='UTF-8'>
<html>
<header>
		
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>
	<script src="http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>

	<title>
		Test
	</title>

</header>
<body> 
	
	<div class = "container" style="">
				
		<div class = "jumbotron" style="">
					
			<h1 style="">
					
				Bootstrap&nbsp;Page
			
			</h1>
		
		
		</div>
	
				
		<div class = "row" style="">
					
			<div class = "col-sm-4" style="">
						
				<h3 style="">
						
					Welcome the the Ring programming language
				
				</h3>
			
						
				<p style="">
						
					Using a scripting language is very fun!
				
				</p>
			
			
			</div>
		
					
			<div class = "col-sm-4" style="">
						
				<h3 style="">
						
					Welcome the the Ring programming language
				
				</h3>
			
						
				<p style="">
						
					Using a scripting language is very fun!
				
				</p>
			
			
			</div>
		
					
			<div class = "col-sm-4" style="">
						
				<h3 style="">
						
					Welcome the the Ring programming language
				
				</h3>
			
						
				<p style="">
						
					Using a scripting language is very fun!
				
				</p>
			
			
			</div>
		
		
		</div>
	
				
		<div class = "row" style="">
					
			<div class = "col-sm-4" style="">
						
				<button class = "btn btn-info btn-lg" data-toggle = "modal" data-target = "#myModal" style="">
						
					Open&nbsp;Large&nbsp;Modal
				
				</button>
			
			
			</div>
		
					
			<div class = "col-sm-4" style="">
						
				<button class = "btn btn-default btn-lg" style="">
						
					default
				
				</button>
			
						
				<button class = "btn btn-primary btn-md" style="">
						
					primary
				
				</button>
			
						
				<button class = "btn btn-success btn-sm" style="">
						
					success
				
				</button>
			
						
				<button class = "btn btn-info btn-xs" style="">
						
					info
				
				</button>
			
						
				<button class = "btn btn-warning" style="">
						
					warning
				
				</button>
			
						
				<button class = "btn btn-danger" style="">
						
					danger
				
				</button>
			
						
				<button class = "btn btn-link" style="">
						
					link
				
				</button>
			
			
			</div>
		
					
			<div class = "col-sm-4" style="">
						
				<button class = "btn btn-default btn-block" style="">
						
					default
				
				</button>
			
						
				<button class = "btn btn-primary btn-block" style="">
						
					primary
				
				</button>
			
						
				<button class = "btn btn-success btn-block" style="">
						
					success
				
				</button>
			
						
				<button class = "btn btn-info btn-block" style="">
						
					info
				
				</button>
			
						
				<button class = "btn btn-warning btn-block" style="">
						
					warning
				
				</button>
			
						
				<button class = "btn btn-danger btn-block" style="">
						
					danger
				
				</button>
			
						
				<button class = "btn btn-link btn-block" style="">
						
					link
				
				</button>
			
			
			</div>
		
					
			<div class = "col-sm-4" style="">
						
				<div class = "btn-group" style="">
							
					<button class = "btn btn-primary" style="">
							
						one
					
					</button>
				
							
					<button class = "btn btn-primary" style="">
							
						two
					
					</button>
				
							
					<button class = "btn btn-primary" style="">
							
						three
					
					</button>
				
				
				</div>
			
			
			</div>
		
					
			<div class = "col-sm-4" style="">
						
				<div class = "btn-group btn-group-lg" style="">
							
					<button class = "btn btn-primary" style="">
							
						one
					
					</button>
				
							
					<button class = "btn btn-primary" style="">
							
						two
					
					</button>
				
							
					<button class = "btn btn-primary" style="">
							
						three
					
					</button>
				
				
				</div>
			
			
			</div>
		
					
			<div class = "col-sm-4" style="">
						
				<div class = "btn-group-vertical btn-group-lg" style="">
							
					<button class = "btn btn-primary" style="">
							
						one
					
					</button>
				
							
					<button class = "btn btn-primary" style="">
							
						two
					
					</button>
				
							
					<button class = "btn btn-primary" style="">
							
						three
					
					</button>
				
				
				</div>
			
			
			</div>
		
		
		</div>
	
				
		<div class = "modal fade" id  = "myModal" style="">
					
			<div class = "modal-dialog modal-lg" style="">
						
				<div class = "modal-content" style="">
							
					<div class = "modal-header" style="">
								
						<button class = "close" data-dismiss = "modal" style="">
								
							&times
						
						</button>
					
								
						<h4 class = "modal-title" style="">
								
							Modal&nbsp;Header
						
						</h4>
					
					
					</div>
				
							
					<div class = "modal-body" style="">
								
						<p style="">
								
							This&nbsp;is&nbsp;a&nbsp;large&nbsp;model.
						
						</p>
					
					
					</div>
				
							
					<div class = "modal-footer" style="">
								
						<button class = "btn btn-default" data-dismiss = "modal" style="">
								
							close
						
						</button>
					
					
					</div>
				
				
				</div>
			
			
			</div>
		
		
		</div>
	
	
	</div>


</body>
</html>

		`)
	}

