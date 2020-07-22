#!ring -cgi

Load "weblib.ring"
Import System.Web

Func Main
  new BootstrapPage {
    divstart([ :class = "container" ])
       divstart([ :class = "jumbotron"  ])
        h1("Bootstrap Page")
      divend() 
      divstart([ :class = :row ])  
        divstart([ :class = "col-sm-4" ])
          h3("Welcome to the Ring programming language")
          p([ :text = "Using a scripting language is very fun!" ])
        divend()
        divstart([ :class = "col-sm-4" ])
          h3("Welcome to the Ring programming language")
          p([ :text = "using a scripting language is very fun!" ])
        divend()
        divstart([ :class = "col-sm-4" ])
          h3("Welcome to the Ring programming language")
          p([ :text = "using a scripting language is very fun!" ])
        divend()
      divend()   
    divend()
  }

