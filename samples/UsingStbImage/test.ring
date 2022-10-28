# Load the library
	load "stbimage.ring"
# Image Information
	width=0	height=0 channels=0
# Ring will Free cData automatically in the end of the program
	cData = stbi_load("ring.jpg",:width,:height,:channels,STBI_rgb)
# Display the output
	? "Size (bytes): " + len(cData)
	? "Width : " + width
	? "Height: " + height
	? "Channels: " + channels
# End of program
	? :done
