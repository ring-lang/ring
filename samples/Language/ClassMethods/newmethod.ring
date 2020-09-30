load "stdlibcore.ring"

new test {
    anyMethodThatDoesNotExist()	# Define and call the new method
    anyMethodThatDoesNotExist()	# Call the new method
}
 
class test
      func braceerror        
           if substr(cCatchError,"Error (R3)")
		? "You are calling a method that doesn't exist!"
		aError = Split(cCatchError," ")
		cMethodName = aError[len(aError)]
		? "The Method Name: " + cMethodName
		AddMethod(self,cMethodName,func {
			? "Hello from the new method!"
		})
		? "We defined the new method!"
		call cMethodName()
           ok