load "stbimage.ring"

width    = 640
height   = 480
channels = 3
cData    = space(width*height*channels)

? "Creating the image..."
t1 = clock()
nIndex=0
for x=1 to height
    for y=1 to width
        cData[nIndex++] = (x*x)%256
        cData[nIndex++] = (x*y)%256
        cData[nIndex++] = (x*2)%256
    next
next
t2 = clock()

# Write the image
? "Writing mynewimage.bmp"
stbi_write_bmp("mynewimage.bmp", width, height, channels, cData)
t3 = clock()

? "Time to create the image : " + ((t2-t1)/clockspersecond()) + " seconds"
? "Time to save the image   : "   + ((t3-t2)/clockspersecond()) + " seconds"

system("mynewimage.bmp")