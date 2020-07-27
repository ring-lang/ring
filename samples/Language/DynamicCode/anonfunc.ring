cDynamicCode = func {
    ? "Code to change at any time!"
}

while true

	call cDynamicCode()

	? "Do you want to change the dynamic code? (Y/N) [Q to quit]: " give cAnswer

	Switch upper(cAnswer)
	on "Y"
	    cDynamicCode = func {
	        ? "We changed our code!"
	    }
	on "N"
	    ? "Ok!"
	on "Q"
	    bye
	off

end

