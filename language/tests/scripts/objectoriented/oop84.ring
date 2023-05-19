? :start
myobj = new Obj { 
	? "before self msg"
	self.msg = :work 
	? "after self msg"
	? "before self data"
	self.data = [6,8] 
	? "after self data"
}
? myobj
? myobj.data
? len(myobj.data)
? :done

class Obj

	msg = :start
	data 

	func setdata value
		? "DATA Setter"
		data = value

	func setmsg value
		? "MSG Setter"
		msg = value