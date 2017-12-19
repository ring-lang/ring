# Generate Documentation from Configuration File
# Author : Mahmoud Fayed <msfclipper@yahoo.com>
# Date : 2017.10.12

#===============================================
C_OUTPUTFILE = "ringconsolecolorsfuncsdoc.txt"
C_CHAPTERNAME = "RingConsoleColors Functions Reference"
cFile = read("consolecolors.cf")
lStart = True		# False = Classes Doc.   True = Functions Doc.
funcAfterClass = ""	# Not used
#===============================================

load "../codegen/gendoc.ring"
