load "stbimage.ring"
load "fastpro.ring"

RVALUE = 1
GVALUE = 2
BVALUE = 3

CIMAGE = "ring.jpg"

# Image Information
	width=0	height=0 channels=0
# Ring will Free cData automatically in the end of the program
        ? "Load image: " + CIMAGE
	cData = stbi_load(CIMAGE,:width,:height,:channels,STBI_rgb)

# Convert to Gray
        cNewData = updateBytesColumn(cData,channels,width*height,255,
			  :mul,RVALUE,0.3,             # R *= 0.3
        		  :mul,GVALUE,0.59,            # G *= 0.59
        		  :mul,BVALUE,0.11,            # B *= 0.11
        		  :merge,RVALUE,GVALUE,        # R += G
        		  :merge,RVALUE,BVALUE,        # R += B
        		  :copy,RVALUE,GVALUE,         # G = R
        		  :copy,RVALUE,BVALUE)         # B = R

# Write the image
? "Writing mynewimage.bmp"
stbi_write_bmp("mynewimage.bmp", width, height, channels, cNewData)
system("mynewimage.bmp")