new DSL {
	200          	    			
	400				important		
	50								
	600				important 
	60
	10 20 30 
	40 50 60			stop
	70 80 90
	800				important
}

class DSL

	nSum = 0		lastvalue  
	stop = False		important	aImportant = []

	func getStop()			stop       = True
	func getImportant()		if !stop   aImportant + lastvalue	end
	func braceExprEval(value)	if !stop   nSum += value   		end 	lastvalue = value 
	func braceEnd()			? "Sum: "+nSum ? "Important: " ? aImportant 

