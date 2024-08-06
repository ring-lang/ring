DELAY   = 100
LED_PIN	= PICO_DEFAULT_LED_PIN 

gpio_init(LED_PIN)
gpio_set_dir(LED_PIN, GPIO_OUT)  

while True 
	gpio_put(LED_PIN, True)
	sleep_ms(DELAY)
	gpio_put(LED_PIN, False)
	sleep_ms(DELAY)
end
