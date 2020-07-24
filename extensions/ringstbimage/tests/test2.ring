# Load the library
	load "stbimage.ring"
# Image Information
	width=0	height=0 channels=0
# Ring will Free cData automatically in the end of the program
	cData = stbi_load("ring2.jpg",:width,:height,:channels,STBI_rgb)
# Display the output
	if cData != NULL
		? "Size (bytes): " + len(cData)
		? "Width : " + width
		? "Height: " + height
		? "Channels: " + channels
		# End of program
		? :done
	else 
		? stbi_failure_reason()
	ok