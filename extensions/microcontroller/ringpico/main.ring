load "picolib.ring"

LED_PIN	= PICO_DEFAULT_LED_PIN 

LED1 	= 14  	LED2	= 15 

aPins = [LED_PIN, LED1, LED2 ] 

for nPin in aPins 
	gpio_init(nPin)	gpio_set_dir(nPin, GPIO_OUT)  
next 

oDelay = new Delay 

oDelay {
	While True 
		gpio_put(LED_PIN, True)
		Delay()
		gpio_put(LED1, True) gpio_put(LED2, False) 
		Delay()
		gpio_put(LED1, False) gpio_put(LED2, True) 
		Delay()
		gpio_put(LED_PIN, False)
		Delay()
	end
}

class Delay

	nDelay = 100

	func delay

		sleep_ms(nDelay)
