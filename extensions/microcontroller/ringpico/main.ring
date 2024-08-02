load "picolib.ring"

DELAY   = 100
LED_PIN	= PICO_DEFAULT_LED_PIN 
LED1 	= 14  	
LED2	= 15 

aPins = [LED_PIN, LED1, LED2 ] 

for nPin in aPins 
	gpio_init(nPin)
	gpio_set_dir(nPin, GPIO_OUT)  
next 

while True 
	gpio_put(LED_PIN, True)					sleep_ms(DELAY)
	gpio_put(LED1	, True)		gpio_put(LED2, False)	sleep_ms(DELAY)
	gpio_put(LED1	, False)	gpio_put(LED2, True)	sleep_ms(DELAY)
	gpio_put(LED_PIN, False)				sleep_ms(DELAY)
end
