# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2017.08.06

#===============================================
C_OUTPUTFILE = "ringfreeglutfuncsdoc.txt"
C_CHAPTERNAME = "RingFreeGLUT Functions Reference"
cFile = read("freeglut.cf")
lStart = True		# False = Classes Doc.   True = Functions Doc.
funcAfterClass = ""	# Not used
#===============================================

load "../codegen/gendoc.ring"
