i = new item
t = new TaskScheduler
t {
	addTask ( i, :myfunction )
	runTask()
}

class item
	func myfunction 
		? 'whatever'
 
class TaskScheduler
	theObject theFunction

   func addTask ( oObject, cMethod)
	theObject = oObject
	theFunction = cMethod + "()"

   func runTask ()
	theObject {
		eval( this.theFunction )
	}
