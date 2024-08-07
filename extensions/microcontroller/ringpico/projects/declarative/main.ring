load "circuit.ring"

SWITCH_PIN = 14
LED_PIN    = 15

func main 

	Circuit {
		LED {
			Pin	= PICO_DEFAULT_LED_PIN
			Blink	= True
			Delay	= 0.1
		}
		LEDSwitch {
			Pin = SWITCH_PIN
			LED { 
				Pin	= LED_PIN
				Blink	= True
				Delay	= 3  
			}
		}
	}
