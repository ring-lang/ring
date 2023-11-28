# Load the library
	load "stbimage.ring"
# Image Information
	width=0	height=0 channels=0
# Ring will Free cData automatically in the end of the program
	cData = stbi_load("ring.jpg",:width,:height,:channels,STBI_rgb)
# Display the output
	if cData != NULL
		? "Size (bytes): " + len(cData)
		? "Width : " + width
		? "Height: " + height
		? "Channels: " + channels
	else 
		? stbi_failure_reason()
		return
	ok

# Write the image
? "Writing mynewimage.bmp"
stbi_write_bmp("mynewimage.bmp", width, height, channels, cData)
? :done