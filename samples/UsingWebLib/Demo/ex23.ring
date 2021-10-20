#!ring -cgi

Load "weblib.ring"
Import System.Web

Func Main
  BootStrapWebPage()
  {
    div
    {
      classname = :container
      div
      {
        classname = :jumbotron
        H1 {   text("Bootstrap Page")   }
      }
      div
      {
        classname = :row
        for x = 1 to 3
          div
          {
            classname = "col-sm-4"
            H3 { html("Welcome to the Ring programming language") }
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
          Button {  classname = "btn btn-danger"         text("danger") }
          Button {  classname = "btn btn-link"          text("link") }
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
              h4 {  classname="modal-title"
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
