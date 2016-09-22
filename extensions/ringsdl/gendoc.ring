# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2016.09.22

#===============================================
C_OUTPUTFILE = "ringlibsdlfuncsdoc.txt"
C_CHAPTERNAME = "RingLibSDL Functions Reference"
cFile = read("libsdl.cf")
lStart = True		# False = Classes Doc.   True = Functions Doc.
#===============================================

load "../codegen/gendoc.ring"
