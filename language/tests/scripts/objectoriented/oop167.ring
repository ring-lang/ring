# Using (ON,OFF) keywords as methods

on()
new myswitch { on() off() }
off()

func on
	? "Hello from ON()"

func off
	? "Hello from OFF()"

class myswitch

	func on
		? "ON"

	func off
		? "OFF"