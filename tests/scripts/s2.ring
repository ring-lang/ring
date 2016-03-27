oMsg = new Msg 
oMsg.Name = "Mahmoud"  
oMsg.see("Hello",(5*2)+3)
oMsg.Sum(4,8)
oMsg.hello()

aMsg = new Msg[10]

aMsg[1].sum(4,2)

class Msg 
 func see Name,age
  see " Name : " + Name  
  see " Age  : " + age
 func Sum x,y
  see x+y
 func hello
  see "hello world"