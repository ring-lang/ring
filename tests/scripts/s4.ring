oMsg = new Msg 
oMsg.Name = "Mahmoud"  
oMsg.see("Hello",5)
oMsg.msgwin = new Window
oMsg.msgwin.show()

class Msg 
 func see 
  see "Hello" + Name  
 func Sum x,y
  see x+y

class Window 
 func show
  see "show window"