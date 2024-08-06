load "mylib.ring"

SWITCH_PIN = 14
LED_PIN    = 15

func main 

	oSwitch	= new LEDSwitch {
		setPin(SWITCH_PIN)
		LED { setPin(LED_PIN) }
	}
	
	while True 
		 oSwitch.process()	
	end
