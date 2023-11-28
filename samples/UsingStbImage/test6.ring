load "stbimage.ring"
load "listpro.ring"

RVALUE = 3
GVALUE = 4
BVALUE = 5

CIMAGE = "ring.jpg"

# Image Information
	width=0	height=0 channels=0
# Ring will Free cData automatically in the end of the program
        ? "Load image: " + CIMAGE
	cData = stbi_load(CIMAGE,:width,:height,:channels,STBI_rgb)

t1 = clock()
aList = bytes2list(:cData,width,height,channels)
t2 = clock()

# Convert to Gray
        updateList(aList,:mul,:col,RVALUE,0.3)             # R *= 0.3
        updateList(aList,:mul,:col,GVALUE,0.59)            # G *= 0.59
        updateList(aList,:mul,:col,BVALUE,0.11)            # B *= 0.11
        updateList(aList,:merge,:col,RVALUE,GVALUE)        # R += G
        updateList(aList,:merge,:col,RVALUE,BVALUE)        # R += B
        updateList(aList,:copy,:col,RVALUE,GVALUE)         # G = R
        updateList(aList,:copy,:col,RVALUE,BVALUE)         # B = R

t3 = clock()
cNewData = list2bytes(aList,channels)
t4 = clock()

# Write the image
? "Writing mynewimage.bmp"
stbi_write_bmp("mynewimage.bmp", width, height, channels, cNewData)
t5 = clock()

? "bytes2List()     Time: " + ( (t2-t1)/clockspersecond() ) + " seconds"
? "updateList()     Time: " + ( (t3-t2)/clockspersecond() ) + " seconds"
? "list2bytes()     Time: " + ( (t4-t3)/clockspersecond() ) + " seconds"
? "stbi_write_bmp() Time: " + ( (t5-t4)/clockspersecond() ) + " seconds"

system("mynewimage.bmp")