i = new item
t = new TaskScheduler
t {
	addTask ( i.myfunction )
	runTask()
}

class item
	myfunction = func {
		? 'whatever'
	}
 
class TaskScheduler
	theFunction

   func addTask ( cFunction)
	theFunction = cFunction

   func runTask ()
		call theFunction()
