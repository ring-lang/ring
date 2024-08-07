circuit = new Circuit

class Circuit

	LED
	LEDSwitch

	aObjects = []

	lCallBraceEnd = True 

	func getLED
		aObjects + new LED 
		return aObjects[len(aObjects)] 	

	func getLEDSwitch 
		aObjects + new LEDSwitch 
		return aObjects[len(aObjects)] 

	func braceEnd 
		if ! lCallBraceEnd return ok
		lCallBraceEnd = False 
		while True 
			for oObj in aObjects 
				oObj.process()
			next 
		end 

class CircuitComponent

	func process

class LED from CircuitComponent

	Pin 

	Delay = 1
	Blink = False
	t1    = clock()

	lStatus		= False 
	lCallBraceEnd	= True 
	lEnableProcess	= True 

	func setPin nPin 
		Pin = nPin 
		gpio_init(Pin)
 		gpio_set_dir(Pin,GPIO_OUT) 

	func Enable 
		lStatus = True
		gpio_put(Pin,True)

	func Disable 
		lStatus = False
		gpio_put(Pin,False)

	func braceEnd 
		if ! lCallBraceEnd return ok
		enable()

	func process
		if ! lEnableProcess return ok
		if Blink and ( ((clock()-t1)/clockspersecond()) > Delay )
			lStatus = ! lStatus 
			gpio_put(Pin,lStatus)
			t1 = clock()
		ok

class LEDSwitch from CircuitComponent

	Pin 
	Status	= False  

	LED	= new LED { lCallBraceEnd = False lEnableProcess = False }

	func setPin nPin 
		Pin = nPin 
		gpio_init(Pin)
 		gpio_pull_up(Pin) 

	func getStatus  
		return gpio_get(Pin)  

	func Process
		LED.process()
		if ! getStatus()
			Status = ! Status 
			if Status 
				LED.enable() 
			else
				LED.disable() 
			ok
			LED.t1 = clock()
			LED.lEnableProcess = Status
			sleep_ms(30)
			while ! getStatus() end  
			sleep_ms(30) 
		ok
