class LED 

	Pin 

	func setPin nPin 
		Pin = nPin 
		gpio_init(Pin)
 		gpio_set_dir(Pin,GPIO_OUT) 

	func Enable 
		gpio_put(Pin,True)

	func Disable 
		gpio_put(Pin,False)

class LEDSwitch 

	Pin 
	Status = False  
	LED = new LED 

	func setPin nPin 
		Pin = nPin 
		gpio_init(Pin)
 		gpio_pull_up(Pin) 

	func getStatus  
		return gpio_get(Pin)  

	func Process
		if ! getStatus()
			Status = ! Status 
			if Status 
				LED.enable()
			else
				LED.disable() 
			ok
			sleep_ms(30)
			while ! getStatus() end  
			sleep_ms(30) 
		ok
